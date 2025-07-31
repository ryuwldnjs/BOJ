#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

vector<vector<int>> graph;
vector<int> a;
int dp[200000+5][2];
//[i][0] : 본인 제외할때 최대 시너지합
//[i][1] : 본인 포함(or x)할때 최대 시너지합
void dfs(int now){

    for(int next: graph[now]){
        dfs(next);
        dp[now][0] += dp[next][1];
    }

    //본인 고려한다해도, 내가 없는게 이득일수도 있음
    dp[now][1] = dp[now][0];
    //본인이 특정 한명과 멘토링잡을때
    for(int next:graph[now]){
        dp[now][1] = max(dp[now][1], dp[now][0] - dp[next][1] + dp[next][0] + a[now] * a[next]);
    }

}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    graph.resize(n+1);
    a.resize(n+1);
    for(int i=2;i<=n;i++){
        int x;cin>>x;
        graph[x].push_back(i);
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1);
    cout<<dp[1][1];
    return 0;
}