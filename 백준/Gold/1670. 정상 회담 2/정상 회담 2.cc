#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;
#define MOD 987654321

ll dp[10000+5];

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    dp[0] = 1;

    for(ll i=2;i<=n;i++){
        for(ll j=0;j<=i-2;j+=2){
            ll l = j;
            ll r = i-2 - j;
            dp[i] += dp[l] * dp[r];
            dp[i] %= MOD;
        }
    }

    cout<<dp[n];
    return 0;
}