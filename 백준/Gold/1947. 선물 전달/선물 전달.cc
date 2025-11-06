#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define MOD 1000000000
ll dp[1000000+5];
// dp[i] = (dp[i-1] + dp[i-2]) * (i-1)
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    dp[0] = 0; dp[1] = 0; dp[2] = 1;

    for(int i=3;i<=n;i++){
        dp[i] = (dp[i-1] + dp[i-2]) * (i-1) % MOD;
        // printf("%lld\n",dp[i]);
    }
    cout<<dp[n];
    return 0;
}