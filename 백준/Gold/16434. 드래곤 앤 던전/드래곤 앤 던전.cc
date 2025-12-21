#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;
struct Info{
    ll t,a,h;
};
vector<Info> rooms;
ll n, attack;

//최대체력=x일때, 용을 쓰러트릴수있는가
bool able(ll x){
    ll cur_h = x;
    ll cur_a = attack;
    
    for(auto room : rooms){
        auto [t,a,h] = room;
        if(t == 1){//전투
            h -= cur_a; //용사의 선빵
            ll cnt = (h+cur_a-1)/cur_a; //몬스터 죽을때까지의 공격 카운트
            cur_h -= cnt * a;
            
            if(cur_h <= 0) return false;
        }
        else{//포션
            cur_a += a;
            cur_h = min(cur_h + h, x);
        }
    }
    return true;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>attack;
    for(ll i=0;i<n;i++){
        ll t,a,h;cin>>t>>a>>h;
        rooms.push_back({t,a,h});
    }

    ll lo=0, hi=1e18;
    for(ll i=0;i<100;i++){
        ll mid = (lo + hi) / 2;
        if(able(mid)) hi = mid;
        else lo = mid+1;
    }

    cout<<lo;
    return 0;
}