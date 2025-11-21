#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;
const ll MOD = 1000000007;
ll dp[1000000+5][3];//[i][j] : i번째 블럭이 위1개/아래1개/둘다 일때

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n;cin>>n;

    dp[0][0] = dp[0][1] = dp[0][2] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 2;

    for(ll i=2;i<=n;i++){
        dp[i][0] = dp[i-1][2] + dp[i-1][1];
        dp[i][1] = dp[i-1][2] + dp[i-1][0];
        dp[i][2] = dp[i-1][2] * 2 + dp[i-1][0] + dp[i-1][1] + dp[i-2][2];

        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
        dp[i][2] %= MOD;
    }

    cout<<dp[n][2];

    return 0;
}



