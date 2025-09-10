#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const ll MOD = 1000000007;

ll power(ll a, ll x){
    ll ret = 1;
    while(x){
        if(x%2) ret  = ret*a % MOD;
        a = a*a % MOD;
        x >>=1;
    }
    return ret;
}

void solve(){
    ll n;cin>>n;
    cout<<power(2, max(0LL,n-2))<<'\n';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}