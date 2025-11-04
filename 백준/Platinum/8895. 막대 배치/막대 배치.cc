#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;

ll dp[25][25];
//dp[i][j] : i개 막대에서 j개 보일때의 경우의 수
//dp[i][j] = dp[i-1][j-1] + (i-1)*dp[i-1][j]
ll nCr[25][25];

void preprocess(){
    for(ll i=0;i<=20;i++){
        nCr[i][0] = nCr[i][i] = 1;
        for(ll j=1;j<i;j++){
            nCr[i][j] = nCr[i-1][j-1] + nCr[i-1][j];
        }
    }

    dp[0][0] = dp[1][1] = 1;
    for(ll i=1;i<=20;i++){
        for(ll j=1;j<=i;j++){
            dp[i][j] = dp[i-1][j-1] + (i-1) * dp[i-1][j];
        }
    }
}

void solve(){
    ll n,l,r;cin>>n>>l>>r;
    ll answer = 0;
    //i에 가장큰 n을 배치함
    for(ll i=0;i<n;i++){
        answer += nCr[n-1][i] * dp[i][l-1] * dp[n-i-1][r-1];
    }
    cout<<answer<<'\n';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    preprocess();
    ll t; cin>>t; while(t--) solve();
    return 0;
}