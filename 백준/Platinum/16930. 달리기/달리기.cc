#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    int x,y;
    int cost;
};
const int INF = 1e9;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int n,m,k;
vector<vector<char>> gym;

bool pass(int x, int y){
    return 1<=x&&x<n+1 && 1<=y&&y<m+1 && gym[x][y] != '#';
}
void bfs(int x1, int y1, int x2, int y2){
    queue<Info> q;
    vector<vector<int>> dist(n+1, vector<int>(m+1, INF));
    q.push({x1, y1, 0});
    dist[x1][y1] = 0;
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int cost = q.front().cost;
        q.pop();
        if(cost > dist[x][y]) continue;
        // if(cost > 5000) break;
        if(x == x2 && y == y2){
            cout<<cost;
            return;
        }
        for(int dir=0;dir<4;dir++){
            
            for(int i=1;i<=k;i++){
                int xx = x + i*dx[dir];
                int yy = y + i*dy[dir];
                if(!pass(xx,yy)) break;
                if(cost >= dist[xx][yy]) break;

                if(cost + 1 < dist[xx][yy]){
                    q.push({xx, yy, cost + 1});
                    dist[xx][yy] = cost + 1;
                }
            }
        }
    }


    cout<<-1;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m>>k;
    gym.resize(n+1, vector<char>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>gym[i][j];
        }
    }
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    
    bfs(x1, y1, x2, y2);
    return 0;
}