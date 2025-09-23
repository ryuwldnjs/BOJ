#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

void solve(){
    ll n;cin>>n;

    ll answer = 0;
    while(n){
        ll val = n % 100LL;
        
        ll ret = val%10 + val/10;
        
        //i번 25빼기연산
        for(int i=1;i<=3;i++){
            if(val < 25 * i) break;
            ll tmp = val - 25 * i;

            ret = min(ret, tmp%10 + tmp/10 + i);
        }

        // cout<<ret<<'\n';
        answer += ret;
        n /= 100LL;
    }
    cout<<answer<<'\n';
}

// 76 54 01 23
// 5
// 1
// 6
// 4


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}