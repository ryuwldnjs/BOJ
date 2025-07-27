#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;
ll n;
vector<ll> a;

ll getMAX(ll mod, ll remain){
    ll cnt = 0;
    for(ll i=0;i<n;i++){
        if(a[i] % mod == remain) cnt++;    
    }
    return cnt;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    srand(1234567890);

    cin>>n;
    a.resize(n);
    for(ll i=0;i<n;i++) cin>>a[i];

    sort(a.begin(), a.end());

    ll answer = (n+1)/2;
    for(ll it=0;it<100;it++){
        ll x = rand() % n;
        ll y = rand() % n;
        if(x > y) swap(x,y);
        if(abs(a[x] - a[y]) <= 1) continue;

        ll mod = abs(a[x] - a[y]);

        for(ll i=2;i*i<=mod; i++){
            if(mod % i == 0){
                ll remain = a[x] % i;

                answer = max(answer, getMAX(i, a[x] % i));
                answer = max(answer, getMAX(mod / i, a[x] % (mod/i)));
            }

        }
        answer = max(answer, getMAX(mod, a[x] % mod));


    }

    cout<<answer;
    return 0;
}