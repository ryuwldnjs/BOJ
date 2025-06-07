#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

void solve(){
    int n;cin>>n;
    priority_queue<ll, vector<ll>,greater<ll>> pq;
    for(int i=0;i<n;i++){
        ll x;cin>>x;
        pq.push(x);
    }
    ll answer = 0;

    for(int i=0;i<n-1;i++){
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        answer += a + b;
        pq.push(a + b);
    }
    cout<<answer<<'\n';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}