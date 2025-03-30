#include <iostream>
#define MOD 1000000007LL
using namespace std;
using ll=long long;
ll pow(ll a, ll x){
    if(x==0) return 1;
    if(x==1) return a % MOD;
    ll ret = pow(a,x/2) % MOD;
    ret = (ret*ret) % MOD;
    if(x%2==0) return ret % MOD;
    else return (ret * a) % MOD;
}
void solve(){
    ll p,n, answer = 0;
    cin>>p>>n;
    // ll now = 1;
    // for(int i=0;i<n;i++){
    //     answer = (answer + now) % MOD;
    //     now = (now*p) % MOD;
    // }
    // for(ll i=1;i<=n;i++){
    //     // answer += n / i;
    //     answer += pow(p, n-i);
    //     answer %= MOD;
    // }

    answer = pow(p, n) - 1LL;
    ll down = pow(p-1, MOD-2) % MOD;
    answer = (answer * down) % MOD;

    cout<<answer<<'\n';
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int q; cin>>q; while(q--) solve();
    return 0;
}