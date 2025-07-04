#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const ll MOD = 1000000007;
ll pow(ll a, ll x){
    ll ret = 1;
    while(x){
        if(x%2) ret = (ret*a) % MOD;
        a = (a*a) % MOD;
        x/=2;
    }
    return ret;
}

ll nCr(ll n, ll r){
    ll ret = 1;
    for(ll i=r;i>1;i--) ret = (ret*i) % MOD;
    ret = pow(ret, MOD-2);
    for(ll i=n;i>n-r;i--) ret = (ret*i) % MOD;
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n,r;cin>>n>>r;
    cout<<nCr(n,r);
    return 0;
}