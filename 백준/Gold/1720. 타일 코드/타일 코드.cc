#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    int dp[35]={1, 1};
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2] * 2;
    }

    int total = dp[n];
    int pailin = dp[n/2];
    if(n%2==0) pailin += dp[n/2 - 1] * 2;

    cout<<(total - pailin)/2 + pailin;
    return 0;
}