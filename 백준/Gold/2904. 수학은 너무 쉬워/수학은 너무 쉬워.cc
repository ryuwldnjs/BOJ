#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int MAX = 1000000;
vector<int> primes;
int factor[MAX];//소인수별 개수

void sieve(){
    vector<bool> isPrime(MAX+1, true);
    for(int i=2;i<=MAX;i++){
        if(!isPrime[i]) continue;
        primes.push_back(i);
        for(int j=i*2;j<=MAX;j+=i){
            isPrime[j] = false;
        }
    }
}


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    sieve();

    int n;cin>>n;
    vector<int> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
        int tmp = a[i];
        for(int i=0;tmp >= primes[i]; i++){
            while(tmp % primes[i] == 0){
                tmp /= primes[i];
                factor[i]++;
            }
        }
    }

    int target = 1;
    for(int i=0;i<primes.size();i++){
        for(int j=0;j<factor[i]/n;j++){
            target *= primes[i];
        }
    }

    int cnt = 0;
    for(int i=0;i<n;i++){
        int needed = target / gcd(a[i], target);

        for(int j=0; needed >= primes[j]; j++){
            while(needed % primes[j] == 0){
                needed /= primes[j];
                cnt++;
            }
        }
    }

    cout<<target<<' '<<cnt;

    return 0;
}