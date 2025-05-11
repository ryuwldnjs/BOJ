#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
/**
 * 괴닉의 정리
 * 이분그래프에서 최대 매칭 = 최소 정점 커버
 */
vector<int> l,r;
vector<vector<int>> graph;
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
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,k;cin>>n>>k;
    graph.resize(n+1);
    l.resize(n+1, -1); r.resize(n+1, -1);
    for(int i=0;i<k;i++){
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
    }

    int answer = 0;
    for(int i=1;i<=n;i++){
        visited = vector<bool>(n+1);
        if(dfs(i)) answer++;
    }
    cout<<answer;
    return 0;
}