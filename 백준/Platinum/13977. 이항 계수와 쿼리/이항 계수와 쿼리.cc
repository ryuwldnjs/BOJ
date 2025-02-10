#include <iostream>
#include <vector>
#define MOD 1000000007LL
using namespace std;
using ll=long long;
/**
 * nCr = n! / r!(n-r)!
 * nCr % p = {n! / (n-r)!r!} % p
 * 근데, 나눗셈은 모듈러연산이 안된다? -> 분모를 없애자
 * (n-r)!r! -> X
 * 1/X % p= X^(-1) % p = X^(p-2) % p  // 페르마 소정리
 */
vector<ll> dp(4000000+1); // dp[n]: n!

 ll pow(ll a, ll x){
    ll result = 1LL;
    while(x){
        if(x % 2LL) result = (result * a) % MOD;
        x >>= 1LL;
        a = (a*a) % MOD;
    }
    return result;
}

ll solve(ll n, ll k){
    ll answer = dp[n] % MOD;
    answer = (answer * pow(dp[n-k], MOD-2)) % MOD;
    answer = (answer * pow(dp[k], MOD-2)) % MOD;
    return answer;
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    ll m; cin>>m;
    dp[0] = 1;
    for(ll i=1;i<=4000000;i++){
        dp[i] = (dp[i-1] * i) % MOD;
    }

    while(m--){
        ll n,k; cin>>n>>k;
        cout<<solve(n,k)<<'\n';
    }
    return 0;
}