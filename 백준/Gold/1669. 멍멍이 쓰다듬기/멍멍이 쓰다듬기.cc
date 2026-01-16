#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;

ll getMaxForDuration(ll duration){
    ll half = duration / 2;
    ll ret = half * (half+1);
    if(duration%2 == 1) ret += half+1;
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll x,y;cin>>x>>y;
    ll gap = y - x;

    //i일동안 늘릴수있는 최대 길이안에 들어오는지 
    for(ll i=0;i<100000;i++){
        if(gap <= getMaxForDuration(i)){
            cout<<i;
            return 0;
        }
    }
    return 0;
}