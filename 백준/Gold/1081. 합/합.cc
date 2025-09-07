#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;

ll getSum(ll num , ll tens){
    ll ret = 0;
    while(num){
        ret += (num%10) * tens;
        num/=10;
    }
    return ret;
}

ll solve(ll n){
    ll tens = 1;
    ll ret = 0;
    while(n > 0){
        while(n%10!=9 && n>0){
            ret += getSum(n, tens);
            n--;
        }

        if(n==0) break;
        n /= 10;

        ret += 45 * (n+1) * tens;
        tens *= 10;
    }
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll L,U;cin>>L>>U;

    cout<<solve(U) - solve(L-1);

    return 0;
}