#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n;
void solve(){
    // int n;cin>>n;
    vector<int> lis;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        int idx = lower_bound(lis.begin(), lis.end(), x) - lis.begin();
        if(idx == lis.size()) lis.push_back(x);
        else lis[idx] = x;
    }
    cout<<lis.size()<<'\n';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    // int t; cin>>t; 
    while(cin>>n) solve();
    return 0;
}