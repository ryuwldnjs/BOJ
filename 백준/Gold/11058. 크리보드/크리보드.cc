#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

ll dp[105] = {0, 1, 2, 3, };

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    
    for(int i=4;i<=n;i++){
        dp[i] = max(dp[i], dp[i-1] + 1);
        
        for(int j=3;j<i;j++){
            dp[i] = max(dp[i], dp[i-j] * (j-1));
        }

    }

    cout<<dp[n];
    return 0;
}