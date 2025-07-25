#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const ll INF = 1e15;
ll n,s;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>s;
    vector<ll> x(n+2), h(n+2);
    
    for(int i=1;i<=n;i++) cin>>x[i];
    for(int i=1;i<=n;i++) cin>>h[i];

    x[0] = -INF;
    x[n+1] = INF;
    int l=s, r=s;
    ll lo=x[s] - h[s], hi=x[s] + h[s];
    while(true){
        if(lo <= x[l-1]){
            l--;
            lo = min(lo, x[l] - h[l]);
            hi = max(hi, x[l] + h[l]);
        }
        else if(hi >= x[r+1]){
            r++;
            lo = min(lo, x[r] - h[r]);
            hi = max(hi, x[r] + h[r]);
        }
        else break;
    }

    for(int i=l;i<=r;i++) cout<<i<<' ';
    return 0;
}