#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;
const ll INF = (ll)1e17;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n;cin>>n;
    vector<ll> a(n), cnt(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    for(ll i=0;i<n-1;i++){
        ll y1 = -INF;
        ll x1 = 1;
        //기울기 y1/x1 < y2/x2여야함
        //-> y1*x2 < y2*x1
        for(ll j=i+1;j<n;j++){
            ll y2 = a[j] - a[i];
            ll x2 = j - i;
            if(y1*x2 < y2*x1){
                y1 = y2;
                x1 = x2;
                cnt[i]++; cnt[j]++;
            }
        }
    }

    ll answer = 0;
    for(ll i=0;i<n;i++){
        // printf("%lld ",cnt[i]);
        answer = max(answer, cnt[i]);
    }
    cout<<answer;
    return 0;
}