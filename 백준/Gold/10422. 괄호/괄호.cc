#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define MOD 1'000'000'007
int dp[2505][2505];

void solve(){
    int n; cin>>n;
    if(n%2 == 1) cout<<0<<'\n';
    else cout<<dp[n/2][n/2]<<'\n';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    for(int j=0;j<=2500;j++) dp[0][j] = 1;
    
    for(int i=1;i<=2500;i++){
        for(int j=i;j<=2500;j++){
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }

    int t; cin>>t; while(t--) solve();
    return 0;
}