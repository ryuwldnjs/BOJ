#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const ll MOD = 1'000'000'007;
const ll MOD2 = MOD * 2;

struct Info{
    ll b,cost;
};

vector<vector<Info>> graph;
vector<ll> subtree;
vector<bool> visited;
ll answer;
ll dfs1(int now){
    visited[now] = true;
    for(auto [next, next_dist]: graph[now]){
        if(visited[next]) continue;
        
        subtree[now] += next_dist * (dfs1(next) + 1);
        subtree[now] %= MOD;
    }
    return subtree[now];
}

void dfs2(int now, ll sum){
    visited[now] = true;
    answer = (answer + sum + MOD) % MOD;
    // printf("%d %lld, %d\n", now, sum, subtree[now]);
    for(auto [next, next_dist]: graph[now]){
        if(visited[next]) continue;
        ll next_sum = sum - next_dist * (1+subtree[next]) + 1;
        next_sum = (next_sum + MOD) % MOD;
        next_sum *= next_dist;
        next_sum = (next_sum + MOD) % MOD;
        next_sum += subtree[next];
        next_sum = (next_sum + MOD) % MOD;
        dfs2(next, next_sum);
    }
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    graph.resize(n+1);
    subtree.resize(n+1);
    for(int i=0;i<n-1;i++){
        ll a,b,c;cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    visited = vector<bool>(n+1);
    dfs1(1);
    visited = vector<bool>(n+1);
    dfs2(1, subtree[1]);

    answer = answer * 500000004 % MOD;

    cout<<answer;
    return 0;
}