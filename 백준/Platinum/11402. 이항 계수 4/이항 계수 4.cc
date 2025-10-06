#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
ll MOD; // 소수일때만 가능
ll dp[2005][2005];

void preProcess(){
    // i_C_j
    for(int i=0;i<=2000;i++){
        dp[i][0] = dp[i][i] = 1;
        for(int j=1;j<i;j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
        }
    }
}

//뤼카 정리
// n, k를 MOD 진수로 나타낸 수 각 자릿수별로 ni_C_ki 계산후 곱연산
// MOD는 소수
ll nCr(ll n, ll k){
    ll ret = 1;
    while(n>0 && k>=0){
        ll ni = n % MOD;
        ll ki = k % MOD;
        if(ni < ki) return 0;
        ret  = (ret * dp[ni][ki]) % MOD;

        n /= MOD;
        k /= MOD;
    }
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    
    ll n,k;cin>>n>>k>>MOD;
    preProcess();

    cout<<nCr(n, k);
        
    return 0;
}