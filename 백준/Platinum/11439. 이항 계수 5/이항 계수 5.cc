#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;
#define SIZE 4000000LL
vector<ll> primes, cnt;//cnt:  소인수의 개수

void preprocess(){
    vector<bool> era(SIZE+5, true);
    for(ll i=2;i<SIZE+5;i++){
        if(!era[i]) continue;
        primes.push_back(i);
        cnt.push_back(0);
        for(ll j=i*2; j<SIZE; j+=i){
            era[j] = false;
        }
    }
}


void solve(ll n, ll sign){
    for(ll i=0;i<primes.size();i++){
        ll pp = primes[i];
        while(pp <= n){
            ll val = (n / pp) * sign;
            cnt[i] += val;
            pp *= primes[i];
        }
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    preprocess();
    ll n,k,m;cin>>n>>k>>m;

    solve(n, 1);
    solve(n-k, -1);
    solve(k, -1);

    ll answer = 1;
    for(ll i=0;i<cnt.size();i++){
        // printf("%d: %d\n", primes[i], cnt[i]);
        ll val = 1;
        for(ll j=0;j<cnt[i];j++){
            val = val * primes[i] % m;
        }
        answer = answer * val % m;
    }

    cout<<answer;
    return 0;
}