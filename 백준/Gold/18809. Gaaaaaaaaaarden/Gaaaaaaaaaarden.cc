#include <bits/stdc++.h>
#define EMPTY 0
#define GREEN 100
#define RED 200
#define FLOWER 300

using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    int y,x;
    int color;
};

int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

vector<vector<int>> board;
vector<pii> candidate;//배양액 뿌릴수있는 땅 리스트
vector<int> type;//후보 땅들에 어떤 걸 뿌려야하는지 체크
int n,m, G, R;

bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<m;
}

int bfs(vector<vector<int>> board){
    queue<Info> q;

    for(int i=0;i<candidate.size();i++){
        if(type[i] == EMPTY) continue;

        auto [y,x] = candidate[i];
        q.push({y, x, type[i]});
        board[y][x] = type[i];
    }

    vector<vector<int>> tmp = board;


    while(!q.empty()){
        int it = q.size();
        vector<Info> diff;

        while(it--){
            auto [y, x, color] = q.front();
            q.pop();

            if(tmp[y][x] == FLOWER) continue;

            for(int i=0;i<4;i++){
                int yy = y + dy[i];
                int xx = x + dx[i];

                if(!pass(yy, xx)) continue;
                if(board[yy][xx] == 1){
                    if(tmp[yy][xx] == 1){
                        tmp[yy][xx] = color;
                        diff.push_back({yy, xx, color});
                        q.push({yy, xx, color});
                    }
                    //직전에는 빈칸인데, 이번에 다른색이 이미 존재한다면
                    else if(tmp[yy][xx] == FLOWER - color){
                        tmp[yy][xx] = FLOWER;
                        diff.push_back({yy, xx, FLOWER});
                    }
                }

            }
        }

        for(auto [y,x,color]: diff) board[y][x] = color;
        
        // board = tmp;
    }


    //FLOWER 개수 체크
    int ret = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j] == FLOWER) ret++;
        }
    }
    return ret;
}



int combi(int idx, int g, int r){
    int ret = 0;
    if(candidate.size() - idx < G-g + R-r) return 0;
    
    if(idx == candidate.size()){
        if(g!=G || r!=R) return 0;
        return bfs(board);
    }

    if(g < G){
        type[idx] = GREEN;
        ret = max(ret, combi(idx+1, g+1, r));
        type[idx] = EMPTY;
    }
    if(r < R){
        type[idx] = RED;
        ret = max(ret, combi(idx+1, g, r+1));
        type[idx] = EMPTY;
    }

    return ret = max(ret, combi(idx+1, g,r));
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m>>G>>R;
    board.resize(n, vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
            if(board[i][j] == 2) {
                candidate.push_back({i,j});
                board[i][j] = 1;
            }
        }
    }

    type.resize(candidate.size());

    cout<<combi(0,0,0);
    return 0;
}