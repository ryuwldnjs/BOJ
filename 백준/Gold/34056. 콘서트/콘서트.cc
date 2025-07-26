#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n;
vector<ll> wall;

void spread(ll c, ll x){
    ll noise = x;
    for(ll i=c+1;i<n;i++){
        if(wall[i] <= noise){
            noise -= wall[i];            
            wall[i] *= 2LL;
        }
        else{
            wall[i] += noise;
            noise = 0;
        }
        if(noise == 0) break;
    }
    noise = x;
    for(ll i=c;i>=0;i--){
        if(wall[i] <= noise){
            noise -= wall[i];            
            wall[i] *= 2LL;
        }
        else{
            wall[i] += noise;
            noise = 0;
        }
        if(noise == 0) break;
    }


}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll q;cin>>n;
    wall.resize(n);
    for(ll i=0;i<n;i++){
        cin>>wall[i];
    }
    cin>>q;
    while(q--){
        ll com;cin>>com;
        if(com == 1){
            ll c,x;cin>>c>>x;
            c--;
            spread(c, x);
        }
        else{
            ll c;cin>>c;
            c--;
            cout<<wall[c]<<'\n';
        }
    }
    return 0;
}