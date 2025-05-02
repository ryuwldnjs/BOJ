#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int a[1005];
int dp[1005][3][35];
int t,w;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>t>>w;
    for(int i=0;i<t;i++){
        cin>>a[i];
    }

    dp[0][1][0] = (a[0] == 1);
    dp[0][2][1] = (a[0] == 2);
    for(int i=1;i<t;i++){
        for(int j=0;j<=w;j++){
            dp[i][1][j] = dp[i-1][1][j] + (a[i] == 1);
            dp[i][2][j] = dp[i-1][2][j] + (a[i] == 2);

            dp[i][1][j] = max(dp[i][1][j], dp[i-1][2][j-1] + (a[i] == 1));
            dp[i][2][j] = max(dp[i][2][j], dp[i-1][1][j-1] + (a[i] == 2));

        }
    }
    int answer = 0;
    for(int i=0;i<=w;i++){
        answer = max(answer, dp[t-1][1][i]);
        answer = max(answer, dp[t-1][2][i]);
    }
    cout<<answer;
    return 0;
}