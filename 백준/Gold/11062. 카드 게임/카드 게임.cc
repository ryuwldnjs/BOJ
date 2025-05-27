#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
vector<vector<int>> dp;
vector<int> a,psum;
int solve(int l, int r){
    if(l == r) return a[l];
    if(dp[l][r] != -1) return dp[l][r];
    int &ret = dp[l][r];

    return dp[l][r] = psum[r] - psum[l-1] - min(solve(l+1, r), solve(l, r-1));
}
void solve(){
    int n;cin>>n;
    a = vector<int>(n+1);
    psum = vector<int>(n+1);
    dp = vector<vector<int>>(n+1, vector<int>(n+1, -1));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        psum[i] = psum[i-1] + a[i];
    }

    cout<<solve(1, n)<<'\n';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}