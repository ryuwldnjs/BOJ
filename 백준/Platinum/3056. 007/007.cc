#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n;
double p[20][20];
double dp[1<<20];
//dp[bit] : B명째까지 보고 bit조합일때의 최대확률
//어차피 켜진 비트수가 B명을 의미함

//idx번째 지미본드
double solve(int bit){
    if(bit == 0) return 1.0;

    double &ret = dp[bit];
    if(ret != -1) return ret;
    ret = 0;

    int idx = n - __builtin_popcount(bit);
    //i번쩌 작업
    for(int i=0;i<n;i++){
        if((bit & (1<<i)) == 0) continue;
        int next_bit = bit ^ (1<<i);
        ret = max(ret, solve(next_bit) * p[idx][i]);
    }

    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            double x;cin>>x;
            p[i][j] = x / 100.0;
        }
    }
    fill(&dp[0], &dp[(1<<20)], -1.0);
    cout<<setprecision(6)<<fixed;
    cout<<solve((1<<n) - 1) * 100;
    return 0;
}