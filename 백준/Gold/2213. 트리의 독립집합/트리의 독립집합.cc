#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
vector<vector<int>> graph, dp;
vector<bool> visited;
vector<int> weight;
//dp[i][x]: i노드가 루트일때 최댓값 
//x=0, i를 사용하지 않을때
//x=1, i를 사욜할때
void dfs(int now){
    visited[now] = true;

    for(int next: graph[now]){
        if(visited[next]) continue;
        dfs(next);
        dp[now][0] += max(dp[next][0], dp[next][1]);
        dp[now][1] += dp[next][0];
    }
    dp[now][1] += weight[now];
}

vector<int> answer;
void trace(int now, int selected){
    visited[now] = true;    
    int sum = 0;

    if(selected) answer.push_back(now);
    
    for(int next:graph[now]){
        if(visited[next]) continue;

        if(selected) trace(next, 0);
        else{
            if(dp[next][0] > dp[next][1]) trace(next, 0);
            else trace(next, 1);
        }
    }

}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    graph.resize(n+1);
    weight.resize(n+1);
    dp.resize(n+1, vector<int>(2));
    for(int i=1;i<=n;i++){
        cin>>weight[i];
    }
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    visited = vector<bool>(n+1);
    dfs(1);

    visited = vector<bool>(n+1);
    trace(1, dp[1][1] > dp[1][0]);

    sort(answer.begin(), answer.end());
    cout<<max(dp[1][0], dp[1][1])<<'\n';
    for(int i:answer) cout<<i<<' ';
    return 0;
}