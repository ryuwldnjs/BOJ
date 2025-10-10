#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;


void solve(){
    double num;cin>>num;
    double answer = 0;
    for(double i=1;i<=num;i++){
        answer += log10(i);
    }
    cout<<(ll)answer + 1<<'\n';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}