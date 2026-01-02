#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;
#define MAX_NUM 1LL<<31
vector<ll> primes;
priority_queue<ll, vector<ll>, greater<ll>> pq;
map<ll, bool> visited;
ll k,n;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>k>>n;
    primes.resize(k);
    for(ll i=0;i<k;i++){
        cin>>primes[i];
    }

    pq.push(1);
    ll MAX = 1;
    for(int i=0;i<n;i++){
        ll now = pq.top(); pq.pop();
        // cout<<now<<'\n';
        // MAX = max(MAX, now);
        for(int j=0;j<k;j++){
            ll next = now * primes[j];
            if(next >= MAX_NUM) break;
            if(visited.count(next) || pq.size() > n && next >= MAX) continue;
            visited[next] = true;
            pq.push(next);
            MAX = max(MAX, next);
        }
    }
    cout<<pq.top();
    return 0;
}