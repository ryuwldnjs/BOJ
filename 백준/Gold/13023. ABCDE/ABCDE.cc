#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
vector<vector<int>> graph;
vector<bool> visited;

int MAX = 0;
void dfs(int now, int depth){
    visited[now] = true;
    if(MAX >= 5) return;
    MAX = max(MAX, depth);

    for(int next: graph[now]){
        if(!visited[next]) dfs(next, depth+1);
    }
    visited[now] = false;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,m; cin>>n>>m;
    graph.resize(n);

    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        visited = vector<bool>(n);
        dfs(i, 1);
    }
    cout<<(MAX >= 5);
    return 0;
}