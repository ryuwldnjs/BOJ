#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

//[1, x]구간에서의 가장 큰 2거듭제곱 약수의 합
ll solve(ll x){
    ll ret = 0;

    for(ll i=1; i<=x; i<<=1LL){
        ll cnt = x / i;//2^i의 배수 개수

        ret -= cnt * (i>>1LL);//2^(i-1)의 배수중 2^i와 겹치는거 제외
        ret += cnt * i;
    }
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll a,b;cin>>a>>b;

    cout<< solve(b) - solve(a-1);
    return 0;
}