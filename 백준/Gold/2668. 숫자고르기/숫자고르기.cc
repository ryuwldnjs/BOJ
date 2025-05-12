#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
vector<bool> visited;
vector<int> graph;
bool dfs(int now, int start){
    visited[now] = true;

    int next = graph[now];
    if(next == start) return true;
    if(!visited[next]) return dfs(next, start);
    return false;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n; cin>>n;
    graph.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>graph[i];
    }

    vector<int> answer;
    for(int i=1;i<=n;i++){
        visited = vector<bool>(n+1);
        if(dfs(i, i)) answer.push_back(i);
    }

    sort(answer.begin(), answer.end());
    cout<<answer.size()<<'\n';
    for(int i: answer){
        cout<<i<<'\n';
    }
    return 0;
}