#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    vector<int> a(n+1), psum(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        psum[i] = psum[i-1] + a[i];
    }
    int k;cin>>k;
    vector<vector<int>> dp(n+1, vector<int>(3));
    for(int i=1;i<k;i++){
        int sum = psum[i];
        dp[i][1] = sum;
    }

    for(int j=1;j<=3;j++){
        for(int i=k;i<=n;i++){
            dp[i][j] = dp[i][j-1];

            int sum = psum[i] - psum[i-k];
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            dp[i][j] = max(dp[i][j], dp[i - k][j-1] + sum);
        }
    }

    cout<<dp[n][3];
    return 0;
}