#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 1e9;
//좌->우, 우->좌, 최종
int dp[1005][1005][3];
int arr[1005][1005];

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,m;cin>>n>>m;
    fill(&dp[0][0][0], &dp[1004][1004][2], -INF);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }

    dp[1][0][2] = 0;
    for(int i=1;i<=m;i++){
        dp[1][i][2] = dp[1][i-1][2] + arr[1][i];
    }

    for(int i=2;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j][0] = max(dp[i-1][j][2], dp[i][j-1][0]) + arr[i][j];
        }
        for(int j=m;j>=1;j--){
            dp[i][j][1] = max(dp[i-1][j][2], dp[i][j+1][1]) + arr[i][j];
        }
        for(int j=1;j<=m;j++){
            dp[i][j][2] = max(dp[i][j][0], dp[i][j][1]);
        }
    }

    cout<<dp[n][m][2];
    return 0;
}