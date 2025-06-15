#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
//1,1,~n,n,n합이 M이하라면
bool able(ll n, ll M){
    return (ll) 3*n*(n+1)/2 <= M;
}
void solve(){
    ll n;cin>>n;
    ll M = (n+2)/3;
    ll l=0LL, r=(ll)1e9;
    for(int i=0;i<100;i++){
        ll mid = (l+r)/2LL;
        if(able(mid, M)) l = mid;
        else r = mid;

    }

    // cout<<r<<' ';
    ll answer=0;
    if(able(r, M)) {
        M -= (ll) 3*r*(r+1)/2;
        answer = (ll) 1 + 3*r + M / (r+1);
    }
    else{
        M -= (ll) 3*l*(l+1)/2;
        answer = (ll) 1 + 3*l + M / (l+1);
    }
    cout<<answer<<'\n';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}