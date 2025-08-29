#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const ll MOD = 1e9;
ll dp[1000000+5];
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n;cin>>n;

    dp[0] = 1;

    for(ll x=0;x<22;x++){
        ll exp = 1LL<<x;

        for(int i=1;i<=n;i++){
            if(i - exp >= 0) dp[i] += dp[i - exp];
            dp[i] %= MOD;
        }
    }

    cout<<dp[n];
    return 0;
}