#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

vector<int> primes;
void sieve(){
    bool visited[2000000]={};
    for(int i=2;i<2000000;i++){
        if(visited[i]) continue;
        primes.push_back(i);

        for(int j=i*2;j<2000000;j+=i){
            visited[j] = true;
        }
    }
    return;
}

void solve(){
    int n;cin>>n;
    if(binary_search(primes.begin(), primes.end(), n)){
        cout<<"0\n";
        return;
    }

    int idx = lower_bound(primes.begin(), primes.end(), n) - primes.begin();
    // printf("%d ", idx);
    cout<<primes[idx] - primes[idx-1] <<'\n';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    sieve();
    int t; cin>>t; while(t--) solve();
    return 0;
}