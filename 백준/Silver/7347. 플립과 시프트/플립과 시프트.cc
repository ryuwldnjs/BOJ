#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

void solve(){
    int n;cin>>n;
    int a=0,b=0;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        if(i%2==0 && x == 1) a++; 
        else if(i%2==1 && x == 1) b++;
    }

    if(n % 2 == 1){
        cout<<"YES\n";
        return;
    }

    if(abs(a-b) <= 1) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}