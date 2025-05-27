#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
vector<vector<int>> graph, dp;
vector<int> weight;
vector<bool> visited;
void dfs(int now){
    visited[now] = true;

    for(int next: graph[now]){
        if(visited[next]) continue;
        dfs(next);
        dp[now][1] += dp[next][0];
        
        // int grand_sum=0;//손자들 선택시 합계
        // for(int target: graph[next]){
        //     if(target == now) continue; //하극상
        //     grand_sum += dp[target][1];
        // }
        // //자식이 선택되거나, 손자들이 선택되어야함
        // if(grand_sum > 0) dp[now][0] += max(dp[next][1], grand_sum);
        
        dp[now][0] += max(dp[next][0], dp[next][1]);
    }
    dp[now][1] += weight[now];
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    graph.resize(n+1);
    dp.resize(n+1, vector<int>(2));
    weight.resize(n+1);
    visited.resize(n+1);

    for(int i=1;i<=n;i++){
        cin>>weight[i];
    }
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    graph[0].push_back(1);
    dfs(0);
    
    cout<<dp[0][0];
    return 0;
}