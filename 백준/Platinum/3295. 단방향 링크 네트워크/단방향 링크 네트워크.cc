#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
vector<vector<int>> graph;
vector<int> l,r;
vector<bool> visited;
bool dfs(int x){
    if(visited[x]) return false;
    visited[x] = true;

    for(int y: graph[x]){
        if(r[y] == -1 || dfs(r[y])){
            r[y] = x;
            l[x] = y;
            return true;
        }
    }
    return false;
}
void solve(){
    int n,m;cin>>n>>m;
    l = r = vector<int>(n, -1);
    graph = vector<vector<int>>(n);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        graph[a].push_back(b);
    }

    int answer = 0;
    for(int i=0;i<n;i++){
        visited = vector<bool>(n);
        if(dfs(i)) answer++;
    }
    cout<<answer<<'\n';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}