#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF=1e9;
vector<int> a;
vector<vector<int>> dp;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n; cin>>n;
    a.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    dp.resize(n+1, vector<int>(2, -INF));
    dp[0][0] = dp[0][1] = 0;
    dp[1][0] = a[1];
    int answer = a[1];
    
    for(int i=2;i<=n;i++){
        dp[i][0] = max(dp[i-1][0] + a[i], a[i]);
        dp[i][1] = max(dp[i-1][0], dp[i-1][1] + a[i]);
        answer = max(answer, dp[i][0]);
        answer = max(answer, dp[i][1]);
    }
    cout<<answer;
    return 0;
}