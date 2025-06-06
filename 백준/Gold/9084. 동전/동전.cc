#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
vector<int> coin;
vector<vector<int>> dp;
int n,m;
//0~idx번째 동전까지 썼을때 x를 만드는 경우의 수
int getAnswer(int idx, int x){
    if(idx == 0 || x < 0) return 0;
    if(x == 0) return 1;

    int &ret = dp[idx][x];
    if(ret != -1) return ret;
    return ret = getAnswer(idx-1, x) + getAnswer(idx, x - coin[idx]);
}
void solve(){
    cin>>n;
    coin = vector<int>(n+1);
    for(int i=1;i<=n;i++){
        cin>>coin[i];
    }
    cin>>m;
    dp = vector<vector<int>>(n+1, vector<int>(m+1, -1));


    // for(int i=1;i<=n;i++){
    //     dp[i][0] = 1;
    //     for(int j=1;j<=m;j++){
    //         dp[i][j] = dp[i-1][j];
    //         if(j - coin[i] >= 0) dp[i][j] += dp[i][j - coin[i]];
    //     }
    // }
    cout<<getAnswer(n, m)<<'\n';
    // cout<<dp[n][m]<<'\n';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}