#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int dy[8] = {0,-1,-1,-1,0,1,1,1};
int dx[8] = {-1,-1,0,1,1,1,0,-1};

int n;
// int board[55][55];
vector<vector<int>> board(55, vector<int>(55));

bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<n;
}

int getWaterbug(int y, int x){
    int ret = 0;
    for(int i=1;i<8;i+=2){
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(!pass(yy, xx)) continue;
        if(board[yy][xx] > 0) ret++;
    }
    return ret;
}


vector<pii> clouds;
void play(int d, int s){
    bool isCloud[55][55]={};

    for(auto [y,x] : clouds){
        int yy = (y + dy[d] * s + n) % n;
        int xx = (x + dx[d] * s + n) % n;
        board[yy][xx]++;
        isCloud[yy][xx] = true;
    }

    vector<vector<int>> tmp = board;
    for(auto [y,x] : clouds){
        int yy = (y + dy[d] * s + n) % n;
        int xx = (x + dx[d] * s + n) % n;
        tmp[yy][xx] += getWaterbug(yy, xx);
    }

    board = tmp;
    clouds.clear();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] >= 2 && !isCloud[i][j]){
                board[i][j] -= 2;
                clouds.push_back({i,j});
            }
        }
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }

    clouds.push_back({n-2,0});
    clouds.push_back({n-2,1});
    clouds.push_back({n-1,0});
    clouds.push_back({n-1,1});

    for(int i=0;i<m;i++){
        int d,s;cin>>d>>s;
        //n마다 제자리로 돌아옴
        play(d-1, s % n);
    }

    int answer = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            answer += board[i][j];
        }
    }

    cout<<answer;
    return 0;
}