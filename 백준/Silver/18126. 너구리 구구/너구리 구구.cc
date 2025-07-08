#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    ll b,cost;
};
vector<ll> dist;
vector<vector<Info>> graph;
vector<bool> visited;
void dfs(int now, ll now_dist){
    visited[now] = true;
    dist[now] = now_dist;
    for(auto [next, next_dist]: graph[now]){
        if(!visited[next]) dfs(next, now_dist + next_dist);
    }
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    dist.resize(n+1);
    graph.resize(n+1);
    visited.resize(n+1);
    for(int i=0;i<n-1;i++){
        ll a,b,c;cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    dfs(1, 0);
    
    cout<<*max_element(dist.begin(), dist.end());
    return 0;
}