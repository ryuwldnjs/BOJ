#include <iostream>
#include <vector>
using namespace std;
struct Info{
    int b, c;
};
vector<vector<int>> parent; // parent[i][j]: i의 2^j번째 부모
vector<vector<Info>> graph;
vector<int> energy, dist;
int n;
void dfs(int now, int prev){
    parent[now][0] = prev;
    for(int i=0;i<graph[now].size();i++){
        int next = graph[now][i].b;
        int cost = graph[now][i].c;
        if(parent[next][0] != -1) continue;
        dist[next] = dist[now] + cost;
        dfs(next, now);
    }
}
void buildSparseTable(){
    for(int j=1;j<20;j++){
        for(int i=1;i<=n;i++){
            if(parent[i][j-1] != -1){
                parent[i][j] = parent[parent[i][j-1]][j-1];
            }
        }
    }
}
int findRoom(int start){
    int now = start;
    for(int i=19;i>=0;i--){
        if(parent[now][i] != -1 && dist[start] - dist[parent[now][i]] <= energy[start]){
            now = parent[now][i];
        }
    }
    return now?now:1;
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n;
    parent.resize(n+1, vector<int>(20, -1));
    graph.resize(n+1);
    energy.resize(n+1);
    dist.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>energy[i];
    }
    for(int i=0;i<n-1;i++){
        int a,b,c; cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    dfs(1, 0);
    buildSparseTable();
    for(int i=1;i<=n;i++){
        cout<<findRoom(i)<<'\n';
    }
    return 0;
}