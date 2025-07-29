#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    int y,x;
};
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};
const int INF = 1e9;

int n,m;
int board[55][55];
vector<Info> virus;
vector<int> target;//선택된 바이러스
int zeroCnt; //점령해야할 0의 개수

bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<n && board[y][x] != 1;
}

int bfs(){
    queue<Info> q;
    bool visited[55][55]={};
    for(int idx: target){
        auto [y,x] = virus[idx];
        q.push({y, x});
        visited[y][x] = true;
    }


    int cnt = 0;
    int time = 0;
    while(!q.empty()){
        int iter = q.size();
        while(iter--){
            auto [y,x] = q.front();
            q.pop();
            if(board[y][x] == 0) cnt++;
            if(cnt == zeroCnt) return time;


            for(int i=0;i<4;i++){
                int yy = y + dy[i];
                int xx = x + dx[i];
                if(!pass(yy, xx)) continue;
                if(!visited[yy][xx]){
                    visited[yy][xx] = true;
                    q.push({yy, xx});
                }
            }
        }
        time++;
    }


    return INF;
}

int solve(int idx){
    int ret = INF;
    if(idx == virus.size()){
        return bfs();
    }

    if(target.size() < m){
        target.push_back(idx);
        ret = min(ret, solve(idx+1));
        target.pop_back();
    }
    ret = min(ret, solve(idx+1));
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
            if(board[i][j] == 2){
                virus.push_back({i,j});
                board[i][j] = 0;
            }
            if(board[i][j] == 0) zeroCnt++;
        }
    }

    int answer = solve(0);
    if(answer == INF) cout<<-1;
    else cout<<answer;

    return 0;
}