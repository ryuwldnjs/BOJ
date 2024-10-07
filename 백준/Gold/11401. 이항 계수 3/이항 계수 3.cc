#include <iostream>
#define MOD 1000000007LL
using namespace std;
using ll=long long;
/**
 * nCr % p = {n! / (n-r)!r!} % p
 * 근데, 나눗셈은 모듈러연산이 안된다? -> 분모를 없애자
 * (n-r)!r! -> X
 * 1/X % p= X^(-1) % p = X^(p-2) % p  // 페르마 소정리
 */
ll n,k;
ll numerator=1, denominator=1;

ll pow(ll a, ll x){ // a^x
    ll result = 1LL;
    while(x){
        if(x%2LL) result = (result*a) % MOD;
        x>>=1LL;
        a = (a*a) % MOD;
    }
    return result;
}
int main(){
    cin>>n>>k;
    for(ll i=n;i>n-k;i--) numerator = (numerator*i) % MOD;
    for(ll i=1;i<=k;i++) denominator = (denominator*i) % MOD;
    
   //  denominator^-1 %p = denominator^p-2 %p
   ll answer = (numerator * pow(denominator, MOD-2)) % MOD;
    cout<<answer;
    return 0;
}