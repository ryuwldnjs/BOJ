#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
regex pattern("(100+1+|01)+");

void solve(){
    string a;cin>>a;
    if(regex_match(a, pattern)) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}