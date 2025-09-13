#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;
const ll INF = 1e9;
//[i][j][0] : i번째를 포함하지 않고, j개 구간일때 최댓값
//[i][j][1] : i번째를 포함하고, j개 구간일때 최댓값
ll dp[105][55][2];

ll a[105];
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n,m;cin>>n>>m;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    fill(&dp[0][0][0],&dp[104][54][1], -INF);
    for(int i=0;i<n;i++) dp[i][0][0] = 0;

    // dp[0][0][0] = 0;
    // dp[0][1][0] = 0;
    dp[0][1][1] = a[0];
    // dp[0][1][0] = 0;
    for(ll i=1;i<n;i++){
        for(ll j=1;j<=m;j++){
            dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]);
            dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]) + a[i];   
            // printf("[%d][%d]: %d %d\n", i,j,dp[i][j][0],dp[i][j][1]);
        }
    }

    cout<<max(dp[n-1][m][0], dp[n-1][m][1]);
    return 0;
}