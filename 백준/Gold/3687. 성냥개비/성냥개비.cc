#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const ll INF = 1e17;
// 2(일) 5 5 4 5 6 3 7 6 6(영)
vector<ll> dp(105, INF);

void solve(){
    int n; cin>>n;
    cout<<dp[n]<<' ';
    if(n%2==1) {
        cout<<7;
        n -= 3;
    }
    while(n){
        cout<<1;
        n-=2;
    }
    cout<<'\n';
    
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    // dp[1] = 9;
    dp[2] = 1;
    dp[3] = 7;
    dp[4] = 4;
    dp[5] = 2;
    dp[6] = 6;
    dp[7] = 8;
    for(int i=8;i<=100;i++){
        for(int j=2;j<=7;j++){
            int next_num = dp[j];
            if(j==6) next_num = 0;
            dp[i] = min(dp[i], dp[i-j]*10 + next_num);
        }
    }
    
    int t; cin>>t; while(t--) solve();
    return 0;
}