#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define MOD 1000000007
bool era[15000000+5];
vector<ll> primes;

void makePrime(){
    memset(era, 1, sizeof(era));
    for(int i=2;i<=15000000;i++){
        if(!era[i]) continue;
        primes.push_back(i);

        for(int j=i*2;j<=15000000;j+=i){
            era[j] = false;
        }
    }
}

ll power(ll a, ll x){
    ll ret = 1;
    while(x){
        if(x%2) ret = ret * a % MOD;
        a = a*a % MOD;
        x/=2;
    }
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    makePrime();
    ll n,m;cin>>n>>m;

    
    ll answer = 1;
    for(ll prime: primes){
        ll pp = prime;
        ll x = 0;
        
        while((n/pp) * (m/pp)){
            x += (n/pp) * (m/pp);
            pp = pp*prime;
        }
        answer = answer * power(prime, x) % MOD;
    }

    cout<<answer;
    return 0;
}