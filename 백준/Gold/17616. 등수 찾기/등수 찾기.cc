#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

bool visited[100000+5];
int dfs(vector<vector<int>> &graph, int now){
    visited[now] = true;
    int ret = 1;
    for(int next : graph[now]){
        if(!visited[next]) ret += dfs(graph, next);
    }
    return ret;
}

vector<vector<int>> graph, reverse_graph;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,m,x;cin>>n>>m>>x;
    graph.resize(n+1);
    reverse_graph.resize(n+1);

    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        graph[a].push_back(b);
        reverse_graph[b].push_back(a);
    }



    int loser = dfs(graph, x) - 1;//x보다 못난 사람
    memset(visited, 0, sizeof(visited));
    int winner = dfs(reverse_graph, x) - 1; //x보다 잘하는사람
    
    cout<<winner + 1 << ' ' << n - loser;
    return 0;
}