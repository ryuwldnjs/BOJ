#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

void solve(){
    vector<int> coins;
    vector<bool> dp(200000);
    dp[0] = true;
    int total = 0;

    int n;cin>>n;
    for(int i=0;i<n;i++){
        int val, cnt;cin>>val>>cnt;
        total += val * cnt;
        for(int j=1; j<=cnt; cnt-=j,j*=2){
            coins.push_back(val * j);
        }
        if(cnt > 0) coins.push_back(val * cnt);
    }

    for(int coin : coins){
        for(int i=50000;i>=0;i--){
            if(dp[i]) dp[i + coin] = true;
        }
    }
    if(total%2==0 && dp[total/2]) cout<<"1\n";
    else cout<<"0\n";

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t=3;  while(t--) solve();
    return 0;
}