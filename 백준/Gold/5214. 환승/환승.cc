#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int BIAS = 100000+10;
struct Info{
    int now;
    int dist;
};
int n,k,m;
vector<vector<int>> graph;
vector<bool> visited;
int bfs(){
    queue<Info> q;

    q.push({1, 0});
    visited[1] = true;
    while(!q.empty()){
        int now = q.front().now;
        int dist = q.front().dist;
        // printf("%d %d\n",now, dist);
        q.pop();
        if(now == n) return dist/2 + 1;

        for(int next: graph[now]){
            if(!visited[next]){
                q.push({next, dist+1});
                visited[next] = true;
            }
        }
    }
    return -1;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>k>>m;
    graph.resize(n + m + BIAS);
    visited.resize(n + m + BIAS);
    for(int i=0;i<m;i++){
        for(int j=0;j<k;j++){
            int x;cin>>x;
            graph[i+BIAS].push_back(x);
            graph[x].push_back(i+BIAS);
        }
    }

    cout<<bfs();
    return 0;
}