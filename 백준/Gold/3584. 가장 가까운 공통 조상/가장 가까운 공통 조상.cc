#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

vector<vector<int>> graph, parent;
vector<int> depth;
void dfs(int now){
    for(int next: graph[now]){
        depth[next] = depth[now] + 1;
        dfs(next);
    }
}

int LCA(int a, int b){
    if(depth[a] < depth[b]) swap(a,b);
    int diff = depth[a] - depth[b];
    for(int i=0;diff;i++){
        if(diff%2) a = parent[a][i];
        diff /= 2;
    }
    
    for(int i=19;i>=0;i--){
        if(parent[a][i] != -1 && parent[a][i] != parent[b][i]){
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    if(a != b) a = parent[a][0];
    return a;
}
void solve(){
    int n;cin>>n;
    graph = vector<vector<int>>(n+1);
    parent = vector<vector<int>>(n+1, vector<int>(20, -1));
    depth = vector<int>(n+1, -1);
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        graph[a].push_back(b);
        // graph[b].push_back(a);
        parent[b][0] = a;
    }
    int start; //루트 노드
    for(int i=1;i<=n;i++){
        if(parent[i][0] == -1) start = i;
    }
    depth[start] = 0;
    dfs(start);

    for(int j=1;j<20;j++){
        for(int i=1;i<=n;i++){
            if(parent[i][j-1] != -1) parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }

    int a,b;cin>>a>>b;
    cout<<LCA(a,b)<<'\n';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}