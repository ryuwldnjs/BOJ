#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    ll x,y,g;
};
const ll MAX = 1e9;

// ax + by = gcd(a,b)를 만족하는, [x, y, gcd] 리턴
// 단, 이문제는 x는 음수여야함
Info ext_gcd(ll a, ll b){
    if(b == 0) return {1, 0, a};
    auto [x1, y1, g] = ext_gcd(b, a % b);
    ll x = y1;
    ll y = x1 - (a/b) * y1;

    while (x >= 0) {
        x -= b / g;
        y += a / g;
    }
    // printf("%d %d\n", x,y);
    return {x, y, g};
}

void solve(){
    ll k,c;cin>>k>>c;
    auto [x, y, GCD] = ext_gcd(k, c);
    if(GCD != 1 || y > MAX) cout<<"IMPOSSIBLE\n";
    else cout<<y<<'\n';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}