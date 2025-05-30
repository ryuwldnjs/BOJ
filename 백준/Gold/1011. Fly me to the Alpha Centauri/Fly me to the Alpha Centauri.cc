#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;
ll xpsum[70000];
//xpsum[i]: 1~i까지의 연속합
void solve(){
    ll x,y;
    cin>>x>>y;
    y -= x;
    x = 0;

    ll target=0;
    for(ll i=1;i<70000;i++){
        if(xpsum[i-1]*2 + i <= y) target = i; 
    }
    y -= xpsum[target-1]*2 + target;
    ll answer = target*2 - 1;
    for(ll i=target;i>=1;i--){
        while(y >= i){
            answer++;
            y -= i;
        }
    }
    cout<<answer<<'\n';

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    for(ll i=1;i<70000;i++){
        xpsum[i] = xpsum[i-1] + i;
    }
    ll t; cin>>t; while(t--) solve();
    return 0;
}