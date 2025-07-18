#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;

vector<ll> gaps;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n,h;cin>>n>>h;
    vector<pii> arr(n);
    for(ll i=0;i<n;i++){
        ll a,b;cin>>a>>b;
        arr[i] = {a,b};
    }

    sort(arr.begin(), arr.end());

    ll last = 0;
    for(ll i=0;i<n;i++){
        if(last < arr[i].first) gaps.push_back(arr[i].first - last - 1);
        last = max(last, arr[i].second);
    }
    if(last < h) gaps.push_back(h - last);
    sort(gaps.begin(), gaps.end());

    vector<ll> psum = gaps;
    for(ll i=1;i<psum.size();i++) psum[i] += psum[i-1];
    ll gapSize = gaps.size();


    ll q;cin>>q;
    while(q--){
        ll t;cin>>t;
        if(gaps.empty()){
            cout<<"0\n";
            continue;
        }

        ll idx = lower_bound(gaps.begin(), gaps.end(), t) - gaps.begin();
        if(idx == gapSize){
            cout<<"0\n";
            continue;
        }

        ll answer = psum.back() - (gapSize - idx) * (t-1);
        if(idx > 0)answer -= psum[idx-1];
        cout<<answer<<'\n';
    }
    return 0;
}