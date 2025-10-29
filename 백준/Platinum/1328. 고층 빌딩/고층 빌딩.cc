#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const ll MOD =  1000000007;

ll nCr[105][105];

ll dp[105][105]; //i개 서로다른 블럭을 j개만 보이게끔 배치하는 경우의 수
// dp[i][j] = dp[i-1][j-1] + (i-1)dp[i-1][j];
// 새로운 제일 작은 블럭을 제일 앞에 두는 1가지 + 그 외 i-1가지(제일 작아서 값 변화X)

void preprocess(){
    nCr[0][0] = 1;
    for(int i=1;i<105;i++){
        nCr[i][0] = nCr[i][i] = 1;
        for(int j=1;j<i;j++){
            nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j]) % MOD;
        }
    }

    dp[0][0] = 1;
    for(int i=1;i<105;i++){
        for(int j=1;j<=i;j++){
            dp[i][j] = (dp[i-1][j-1] + (i-1)*dp[i-1][j]) % MOD;
            
        }
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n,l,r;cin>>n>>l>>r;
    preprocess();


    ll answer = 0;
    //i번째에 가장 큰 n빌딩을 둘때
    for(int i=1;i<=n;i++){
        ll ret = nCr[n-1][i-1];
        ret = ret * dp[i-1][l-1] % MOD;
        ret = ret * dp[n-i][r-1] % MOD;
        answer = (answer + ret) % MOD;
    }

    cout<<answer;
    return 0;
}