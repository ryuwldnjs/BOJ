#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
ll m;

ll power(ll a, ll x){
    ll ret = 1LL;
    
    while(x){
        if(x%2) ret = (__int128)ret * a % m;
        a = (__int128)a*a % m;
        x /= 2;
    }
    return ret;

}

//X[n] = a^n*X[0] + (1+a+a^2+..a^(n-1))*c
//등비수열합 S[2k] = S[k] + a^k * S[k]
//S[k] * (1 + a^k)


//등비수열 1+ a..a^x의 합
// 항 개수 = x+1개임을 주의
ll powerSum(ll a, ll x){
    if(x<0) return 0;
    if(x==0) return (__int128)1LL % m;
    if(x==1) return (__int128)(a+1) % m;

    if(x % 2 == 0) return ((__int128)powerSum(a, x-1) + (__int128)power(a, x)) % m;
    else return ((__int128)powerSum(a, x/2) * ((__int128)1 + power(a, x/2+1))) % m;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll a,c,x0,n,g;
    cin>>m>>a>>c>>x0>>n>>g;

    ll Xn;
    if(a == 1) Xn = (__int128)((__int128)x0 + c*n) % m;
    else Xn = (__int128)((__int128)power(a, n)*x0 + (__int128)c*powerSum(a,n-1)) % m;
    
    ll answer = Xn % g;
    cout<<answer;
    return 0;
}