#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

ll dp[40][40];
ll nCr(ll n, ll r){
    if(r==0 || r==n) return 1;
    
    ll &ret = dp[n][r];
    if(ret != 0) return ret;
    return ret = nCr(n-1, r-1) + nCr(n-1, r);
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll N,L,I; cin>>N>>L>>I;
    I--;

    ll ones = L;
    string answer;
    for(ll i=N-1;i>=0;i--){
        ll cnt = 0;
        for(ll j=0;j<=min(ones,i);j++){
            cnt += nCr(i, j);
        }
        
        if(I >= cnt){
            I -= cnt;
            ones--;
            answer.push_back('1');
        }
        else answer.push_back('0');
    }

    cout<<answer;
    return 0;
}