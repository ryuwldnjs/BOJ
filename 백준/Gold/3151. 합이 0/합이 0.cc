#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;
const ll BIAS = 20000;
ll cache[50000];
ll n;
ll a[10000+5];

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        cache[a[i] + BIAS]++;
    }

    ll answer = 0;
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            ll target = -(a[i] + a[j]);

            answer += cache[target + BIAS];
            if(a[i] == target) answer--;
            if(a[j] == target) answer--;
            // printf("%d\n", answer);
        }
    }

    //3C2가지 중복 고려
    cout<<answer / 3;
    return 0;
}