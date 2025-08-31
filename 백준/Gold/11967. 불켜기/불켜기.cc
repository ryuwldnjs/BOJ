#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};
int n,m;

// 1based
bool pass(int y, int x){
    return 0<y&&y<=n && 0<x&&x<=n;
}

vector<pii> board[105][105];

bool visited[105][105], light[105][105];

void bfs(){
    queue<pii> q;
    visited[1][1] = light[1][1] = true;

    q.push({1,1});

    while(!q.empty()){
        auto [y,x] = q.front();
        q.pop();

        for(auto [yy,xx]: board[y][x]){
            light[yy][xx] = true;
        
            for(int i=0;i<4;i++){
                int yyy = yy + dy[i];
                int xxx = xx + dx[i];
                if(!pass(yyy,xxx)) continue;
                if(visited[yyy][xxx] && !visited[yy][xx]){
                    visited[yy][xx] = true;
                    q.push({yy,xx});
                }
            }
        }

        for(int i=0;i<4;i++){
            int yy = y + dy[i];
            int xx = x + dx[i];
            if(!pass(yy, xx)) continue;
            if(light[yy][xx] && !visited[yy][xx]){
                visited[yy][xx] = true;
                q.push({yy,xx});
            }
        }
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int y,x,a,b;cin>>y>>x>>a>>b;
        board[y][x].push_back({a,b});
    }

    bfs();

    int answer = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(light[i][j]) answer++;
        }
    }

    cout<<answer;
    return 0;
}