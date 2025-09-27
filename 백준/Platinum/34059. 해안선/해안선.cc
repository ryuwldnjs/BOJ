#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD = 1000000007;
ll fact[1000000+5];

ll power(ll a, ll x){
    ll ret = 1;
    while(x){
        if(x%2) ret = (ret * a) % MOD;
        a = (a*a) % MOD;
        x /= 2;
    }
    return ret;
}

ll nCr(ll n, ll r){
    ll up = fact[n];
    ll down = (fact[r] * fact[n-r]) % MOD;

    ll ret = (up * power(down, MOD-2)) % MOD;
    return ret;
}
ll answer;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    fact[0] = 1;
    for(ll i=1;i<1000000+5;i++){
        fact[i] = (fact[i-1] * i ) % MOD;
    }
    ll n,a,b;cin>>n;
    cin>>a>>b;
    if(a > b) swap(a,b);

    //인접해있음
    if(b - a == 1){
        ll x = a - 2;
        ll y = n - b;
        
        for(ll i=0;i<y;i++){
            answer += nCr(i+x, i) * power(2, y-i-1);
            answer %= MOD;

        }

        for(ll i=0;i<x;i++){
            answer += nCr(i+y, i) * power(2, x-i-1);
            // printf("%lld\n",(nCr(i+y, i) * power(2, x-i-1)) % MOD);
            answer %= MOD;
        }
        answer += nCr(y+x, y) * 2;
        answer %= MOD;

    }
    //떨어져있을떄
    else{
        ll x1 = a - 2;
        ll x2 = n - b;
        ll y = n - 3 - x1-x2;

        answer += power(2, y);
        answer %= MOD;
        answer = (answer * nCr(x1+x2, x1)) % MOD; 
    }

    answer %= MOD;
    
    cout<<answer;
    return 0;
}





// //떨어져있을떄
// else{
//     ll x1 = a - 2;
//     ll x2 = n - b;
//     ll y = n - 3 - x1-x2;

//     answer += power(2, y);
//     answer %= MOD;
//     answer = (answer * nCr(x1+x2, x1)) % MOD; 
// }