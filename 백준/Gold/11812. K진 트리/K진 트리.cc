#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

ll n,k,q;

ll solve(ll a, ll b){
    ll ret = 0;

    if(k == 1) return abs(a-b);

    while(a != b){
        if(a > b) a = (a + k - 2) / k;
        else b = (b + k - 2) / k;
        ret++;
    }

    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>k>>q;

    while(q--){
        ll x,y;cin>>x>>y;
        cout<<solve(x,y)<<'\n';
    }
    return 0;
}