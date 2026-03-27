#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;

ll n,k;
ll psum;
map<ll, ll> m;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>k;

    ll answer = 0;
    m[0] = 1; //빈 리스트
    for(ll i=0;i<n;i++){
        ll a; cin>>a;
        psum += a; // psum[i] - k = psum[j-1]
        answer += m[psum - k];
        m[psum]++;
    }
    cout<<answer;
    return 0;
}