#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;
struct Info{
    int idx;
    int cost;
};
vector<vector<int>> graph;
vector<bool> visited;
int n, MAX;
int dfs(int now){
    int partialMAX = 1;
    visited[now] = true;

    for(int i=1;i<=n;i++){
        if(now == i || graph[now][i] == INF) continue;
        if(!visited[i]) partialMAX = max(partialMAX, dfs(i) + 1);
    }

    return partialMAX;
}
int main(){
    cin>>n;
    graph = vector<vector<int>>(n+1, vector<int>(n+1, 1));
    visited = vector<bool>(n+1);
    for(int i=0;i<n;i++){
        int u,v; cin>>u>>v;
        graph[u][v] = INF;
        graph[v][u] = INF;
    }

    for(int i=1;i<=n;i++){
        visited = vector<bool>(n+1);
        MAX = max(MAX, dfs(i));
//        printf("%d ", MAX);

    }
    cout<<MAX;
    return 0;
}