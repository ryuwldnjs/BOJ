#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;
struct Info{
    ll b,cost;
};
vector<vector<Info>> graph;
vector<vector<ll>> parent;
vector<ll> dist, depth;
void dfs(ll now){
    for(ll i=0;i<graph[now].size();i++){
        ll next = graph[now][i].b;
        if(dist[next] != -1) continue;
        dist[next] = dist[now] + graph[now][i].cost;
        depth[next] = depth[now] + 1;
        parent[next][0] = now;
        dfs(next);
    }
}
ll LCA(ll a, ll b){
    if(depth[a] < depth[b]) swap(a,b);
    ll diff = depth[a] - depth[b];
    for(ll i=0;diff;i++){
        if(diff%2) a = parent[a][i];
        diff /= 2;
    }

    for(ll i=19;i>=0;i--){
        if(parent[a][i] != -1 && parent[a][i] != parent[b][i]){
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    if(a != b) a = parent[a][0];
    return a;

}
ll getDist(ll a, ll b){
    ll lca = LCA(a,b);
    return dist[a] + dist[b] - dist[lca] * 2;
}

ll findVertex(ll a, ll b, ll k){
    k--;
    ll lca = LCA(a,b);
    //depth[a] = 4
    //depth[b] = 2
    //depth[lca] = 1
    //k = 5
    if(depth[a] - depth[lca] < k){
        k = depth[a] + depth[b] - depth[lca]*2 - k;
        swap(a,b);
    }

    for(ll i=0;k;i++){
        if(k%2) a = parent[a][i];
        k /= 2;
    }
    return a;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n;cin>>n;
    graph.resize(n+1);
    for(ll i=0;i<n-1;i++){
        ll a,b,c;cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    dist.resize(n+1, -1);
    depth.resize(n+1, -1);
    parent.resize(n+1, vector<ll>(20, -1));
    dist[1] = 0;
    depth[1] = 0;
    // parent[1][0] = 0;
    dfs(1);

    //LCA 전처리
    for(ll j=1;j<20;j++){
        for(ll i=1;i<=n;i++){
            if(parent[i][j-1] != -1) parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }



    ll q;cin>>q;
    while(q--){
        ll com;cin>>com;
        if(com == 1){
            ll a,b;cin>>a>>b;
            cout<<getDist(a,b)<<'\n';
        }
        else{
            ll a,b,k;cin>>a>>b>>k;
            cout<<findVertex(a,b, k)<<'\n';
        }
    }
    return 0;
}