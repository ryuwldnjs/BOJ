#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;

vector<ll> names[25];
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n,k;cin>>n>>k;
    for(ll i=0;i<n;i++){
        string name;cin>>name;
        names[name.size()].push_back(i);
    }

    ll answer = 0;
    for(ll i=2;i<=20;i++){
        if(names[i].empty()) continue;
        sort(names[i].begin(), names[i].end());
    
        for(ll j=0;j<names[i].size();j++){
            ll idx = upper_bound(names[i].begin(), names[i].end(), names[i][j] + k) - names[i].begin() - 1;
            
            answer += idx - j;
        }
    }

    cout<<answer;
    return 0;
}