#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const ll INF = (ll)1e15;
ll n,m;
ll answer;
vector<pll> arr;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    answer = m;

    for(ll i=0;i<n;i++){
        ll a,b;cin>>a>>b;
        if(a < b) continue;
        arr.push_back({b,a});
    }
    sort(arr.begin(), arr.end());
    arr.push_back({INF, INF});

    ll l = 0;
    ll r = 0;
    for(int i=0;i<arr.size();i++){
        if(arr[i].first <= r) r = max(r, arr[i].second);
        else{
            answer += 2LL * (r - l);
            l = arr[i].first;
            r = arr[i].second;
        }
        // printf("%d %d %d\n",l,r,answer);
    }
    cout<<answer;
    return 0;
}