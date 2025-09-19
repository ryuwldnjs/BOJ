#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;

ll dp[250000+5];
ll a[250000+5];

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n;cin>>n;
    for(ll i=0;i<n;i++) cin>>a[i];

    ll answer = 0;
    for(ll i=1;i<n;i++){
        
        ll j=0;
        for(;(a[i]<<j) < a[i-1]; j++);

        ll k=0;
        for(;(a[i-1]<<(k+1)) <= a[i]; k++);

        dp[i] = max(0LL, dp[i-1] + j - k);
        // printf("%d: %d, %d, %d\n", i, dp[i], j, k);
        answer += dp[i];
    }

    cout<<answer;
    return 0;
}