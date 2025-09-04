#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;
struct Info{
    ll a,b,c;
};
ll n,k,d;
vector<Info> rules;

//x번 상자까지 봤을때, 도토리수가 d이상인가?
bool able(ll x){
    ll cnt = 0;
    for(auto [a,b,c]: rules){
        if(x < a) continue;
        cnt += min((x - a) / c + 1, (b - a) / c + 1);
    }

    return cnt >= d;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>k>>d;
    for(ll i=0;i<k;i++){
        ll a,b,c;cin>>a>>b>>c;
        rules.push_back({a,b,c});
    }


    ll lo=1;
    ll hi=2e9;
    ll limit = log2(hi) + 1;
    for(ll i=0;i<limit; i++){
        ll mid = (lo+hi) / 2;
        if(able(mid)) hi = mid;
        else lo = mid + 1;
    }

    if(able(lo)) cout<<lo;
    else cout<<hi;
    return 0;
}