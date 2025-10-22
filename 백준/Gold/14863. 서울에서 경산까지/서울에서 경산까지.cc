#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;
const ll INF = 1e18;

ll dp[105][100000+5];
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n,k;cin>>n>>k;
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

    for(ll idx=1;idx<=n;idx++){
        //도보
        ll w,v;cin>>w>>v;
        for(ll i=w;i<=k;i++){
            if(dp[idx-1][i-w] == -1) continue;
            dp[idx][i] = max(dp[idx][i], dp[idx - 1][i - w] + v);
        }
        //자전거
        cin>>w>>v;
        for(ll i=w;i<=k;i++){
            if(dp[idx-1][i-w] == -1) continue;
            dp[idx][i] = max(dp[idx][i], dp[idx - 1][i - w] + v);
        }
    }

    ll answer = 0;
    for(ll i=0;i<=k;i++){
        answer = max(answer, dp[n][i]);
    }

    cout<<answer;
    return 0;
}