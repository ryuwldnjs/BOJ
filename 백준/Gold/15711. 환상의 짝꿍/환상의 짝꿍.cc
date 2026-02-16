#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
vector<ll> primes;

void sieve(){
    vector<bool> visited(2000000+10+5, false);
    for(ll i=2;i<=2000000+10; i++){
        if(visited[i]) continue;
        primes.push_back(i);
        for(ll j=i*2; j<=2000000+10; j+=i){
            visited[j] = true;
        }
    }
}

bool isPrime(ll num){
    for(ll i=0;primes[i]*primes[i]<=num;i++){
        if(num%primes[i] == 0) return false;
    }
    return true;
}

void solve(){
    ll a,b,num;cin>>a>>b;
    num = a + b;

    if(num <= 3LL) cout<<"NO\n";
    else if(num % 2LL == 0) cout<<"YES\n";
    else{ //3보다 큰 홀수n = n-2 + 2로 분리가능
        if(isPrime(num-2)) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return;
}


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    sieve();
    int t; cin>>t; while(t--) solve();
    return 0;
}