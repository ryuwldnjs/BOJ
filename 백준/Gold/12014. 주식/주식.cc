#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

void solve(){
    int n,k;cin>>n>>k;
    vector<int> lis;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        int idx = lower_bound(lis.begin(), lis.end(), x) - lis.begin();
        if(idx == lis.size()) lis.push_back(x);
        else lis[idx] = x;
    }

    if(lis.size() >= k) cout<<"1\n";
    else cout<<"0\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<'\n';
        solve();
    }
    return 0;
}