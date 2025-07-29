#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;


    for(int i=1;i<=n/2;i++){
        cout<<i<<' '<<n-i+1<<' ';
    }
    if(n%2) cout<<n/2+1;
    return 0;
}