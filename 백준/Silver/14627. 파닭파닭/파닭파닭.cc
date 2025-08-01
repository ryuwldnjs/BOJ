#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

ll s,c;
vector<ll> pa;
bool able(ll x){
    ll cnt = 0;
    for(int i=0;i<s;i++){
        cnt += pa[i] / x;
    }
    return cnt >= c;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>s>>c;
    pa.resize(s);
    for(int i=0;i<s;i++){
        cin>>pa[i];
    }

    ll l=1, r=2e9;
    int it = log2(r) + 1;
    for(int i=0;i<it;i++){
        ll mid = (l+r)/2;
        if(able(mid)) l = mid;
        else r = mid-1;
    }

    ll total = accumulate(pa.begin(), pa.end(), 0LL);
    if(able(r)) cout<<total - r * c;
    else cout<<total - l * c;
    return 0;
}