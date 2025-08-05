#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;
vector<ll> arr;
ll n,k;

ll lcm(ll a, ll b){
    return a / gcd(a,b) * b;
}

//idx번쨰 숫자, remain번 더 곱할수있을때
ll combi(ll idx, ll remain, ll val){
    ll ret = 0;
    if(remain == 0){
        return n / val;
    }

    if(idx >= k) return 0;
    if(val > n) return 0;

    ret += combi(idx + 1, remain - 1, lcm(val, arr[idx]));
    if(k - idx > remain) ret += combi(idx + 1, remain, val);
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>k;
    arr.resize(k);
    for(ll i=0;i<k;i++){
        cin>>arr[i];
    }


    ll answer = 0;
    for(ll i=1;i<=k;i++){
        if(i % 2 == 1) answer += combi(0, i, 1);
        else answer -= combi(0, i, 1);
        // printf("%d\n", combi(0, i, 1));
    }

    cout<<answer;
    return 0;
}