#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

string s = " moo";
//길이 len인 n번째 수열에서 k번째 원소 찾기
char solve(ll len, ll n, ll k){
    if(n == 0) return s[k];

    ll a = (len - n - 3) / 2;
    ll b = a + n + 3;

    if(k <= a) return solve(a, n-1, k);
    else if(k == a+1) return 'm';
    else if(k <= b) return 'o';
    else return solve(a, n-1, k - b);
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n,k;cin>>k;
    n = k;
    ll len = 3;
    for(ll i=1;i<=k;i++){
        len = len*2 + i+3;
        if(len >= k){
            n = i;
            break;
        }
    }

    cout<<solve(len, n, k);
    return 0;
}