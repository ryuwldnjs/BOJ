#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n;cin>>n;
    vector<ll> d(n);
    for(int i=0;i<n;i++) cin>>d[i];
    sort(d.begin(), d.end());
    
    if(n == 1 && d[0] == 1) {
        cout<<"Happy";
        return 0;
    }

    ll sum = 0;
    for(int i=0;i<n-1;i++) sum += d[i];

    if(d[n-1] > sum) cout<<"Unhappy";
    else cout<<"Happy";
    
    return 0;
}