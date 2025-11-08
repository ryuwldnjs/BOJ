#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const ll MOD = 1000000009LL;

ll dp[40000][3];
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n;cin>>n;
    dp[0][0] = 1;

    for(int i=1;i<n;i++){
        ll val = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % MOD;
        dp[i][0] = val;
        dp[i][1] = val;
        dp[i][2] = val;
    }

    ll answer = (dp[n-1][2] + dp[n-1][1]) % MOD;
    cout<<answer;
    return 0;
}