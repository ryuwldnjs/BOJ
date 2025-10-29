#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n,k;
int v[1000+5], w[1000+5];
int dp[1000+5][10000+5];
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        cin>>v[i]>>w[i];
    }

    int answer = 0;
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++){
            dp[i][j] = dp[i-1][j];
            if(j - w[i] >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j - w[i]] + v[i]);
            // answer = max(answer, dp[i][j]);
        }
    }
    cout<<dp[k][n];
    return 0;
}