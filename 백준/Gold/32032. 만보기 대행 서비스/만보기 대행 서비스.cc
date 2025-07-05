#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n,d;cin>>n>>d;
    vector<ll> plus, minus;
    for(ll i=0;i<n;i++){
        ll x;cin>>x;
        if(x>0) plus.push_back(x);
        else minus.push_back(x);
    }
    sort(plus.begin(), plus.end());
    sort(minus.begin(), minus.end());

    ll answer = 0;
    if(plus.size()) answer += plus.back() * 2 + d;
    if(minus.size()) answer += -minus.front() * 2 + d;
    

    if(plus.size() && minus.size()){
        ll LRL = -minus.front() * 4 + plus.back() * 2 + d;
        ll RLR = -minus.front() * 2 + plus.back() * 4 + d;
        answer = min(answer, min(LRL, RLR));

        ll LRLR = (-minus.front() + plus.back()) * 4
                + max(d - (-minus.front()+plus.back())*2, 0LL)
                + max(d - ((-minus.front() + plus.back())*2 + max(d - (-minus.front()+plus.back())*2, 0LL)), 0LL);
        
        // printf("%lld\n", LRLR);
        answer = min(answer, LRLR);
    }
    cout<<answer;
    return 0;
}