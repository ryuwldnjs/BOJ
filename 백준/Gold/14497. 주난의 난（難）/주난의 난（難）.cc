#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    int y,x;
    int cost;
    bool operator<(const Info &other) const{
        return cost > other.cost;
    }
};
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};
const int INF = 1e9;

int n,m;
char board[305][305];
bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<m;
}
int dijkstra(int y1, int x1, int y2, int x2){
    priority_queue<Info> pq;
    vector<vector<int>> dist(305, vector<int>(305, INF));
    pq.push({y1, x1, 0});
    dist[y1][x1] = 0;

    while(!pq.empty()){
        auto [y,x,cost] = pq.top();
        pq.pop();
        if(cost > dist[y][x]) continue;

        for(int i=0;i<4;i++){
            int yy = y + dy[i];
            int xx = x + dx[i];
            if(!pass(yy,xx)) continue;
            int next_cost = cost + (board[yy][xx]=='0' ? 0 : 1);

            if(next_cost >= dist[yy][xx]) continue;
            pq.push({yy, xx, next_cost});
            dist[yy][xx] = next_cost;
        }
    }

    return dist[y2][x2];
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    int y1,x1,y2,x2;cin>>y1>>x1>>y2>>x2;
    y1--; x1--; y2--; x2--;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }
    cout<<dijkstra(y1,x1,y2,x2);
    return 0;
}