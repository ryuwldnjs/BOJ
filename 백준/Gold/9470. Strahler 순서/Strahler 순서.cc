#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

void solve(){
    int k,m,p;cin>>k>>m>>p;
    vector<vector<int>> graph(m+1);
    vector<int> indegree(m+1);
    vector<pii> dp(m+1); //[MAX, cnt]
    for(int i=0;i<p;i++){
        int a,b;cin>>a>>b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;
    for(int i=1;i<=m;i++){
        if(indegree[i] == 0) {
            q.push(i);
            dp[i] = {1,1};
        }
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();
        
        //최댓값이 2개이상
        if(dp[now].second > 1) dp[now].first++;
        // printf("%d %d\n", now, dp[now].first);
        for(int next: graph[now]){
            if(--indegree[next] == 0) q.push(next);
            if(dp[now].first > dp[next].first) dp[next] = {dp[now].first, 1};
            else if(dp[now].first == dp[next].first) dp[next].second++;
        }
    }

    cout<<k<<' '<<dp[m].first<<'\n';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}