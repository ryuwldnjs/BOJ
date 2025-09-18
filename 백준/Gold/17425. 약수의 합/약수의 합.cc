#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int MAX = 1000000;
ll dp[MAX+5];

void init(){
    for(int i=1;i<=MAX;i++){
        for(int j=i;j<=MAX;j+=i){
            dp[j] += i;
        }
        dp[i] += dp[i-1];
    }
}

void solve(){
    int n;cin>>n;
    cout<<dp[n]<<'\n';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    init();
    int t; cin>>t; while(t--) solve();
    return 0;
}