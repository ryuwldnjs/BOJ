#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

vector<vector<int>> graph;
vector<bool> visited; 
//리프노드 개수 반환
int dfs(int now){
    visited[now] = true;
    int ret = 0;
    bool isLeaf = true;
    for(int next: graph[now]){
        if(!visited[next]){
            isLeaf = false;
            ret += dfs(next);
        } 
    }

    return ret + isLeaf;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,w;cin>>n>>w;
    graph.resize(n+1);
    visited.resize(n+1);

    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int leaf_cnt = dfs(1);
    cout.precision(6);
    cout << fixed <<(double) w / leaf_cnt;
    return 0;
}