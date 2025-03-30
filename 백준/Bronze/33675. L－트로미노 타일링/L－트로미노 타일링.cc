#include <iostream>
using namespace std;
using ll=long long;
void solve(){
    ll n; cin>>n;
    ll answer = 0;
    if(n%2==0){
        n /=2;
        answer = (1LL<<n);
    }
    cout<<answer<<'\n';
}
int main(){
int t; cin>>t; while(t--) solve();
    return 0;
}