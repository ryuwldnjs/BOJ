#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 1e9;
int n,m;
int a[1005], dp[1005][2];
// dp[i] : i번쨰 원소까지 넣었을때, 제곱의 합의 최솟값
// dp[i][0] = (j<i) MIN(dp[j-1][0] + {j~i}를 적고 남은 칸)
// dp[i][1] = (j<i) MIN(dp[j-1][0])

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    fill(&dp[0][0], &dp[1004][1], INF);
    dp[0][0] = dp[0][1] = 0;
    
    for(int i=1;i<=n;i++) cin>>a[i];

    //a[i]를 마지막줄 마지막에 넣는 상황
    for(int i=1;i<=n;i++){
        int remain = m+1; //이번 줄에 남은 칸
        for(int j=i;j>=1;j--){
            remain -= a[j] + 1; //이름 사이 공백1칸  포함
            if(remain < 0) break;

            dp[i][0] = min(dp[i][0], dp[j-1][0] + remain * remain);
            dp[i][1] = min(dp[i][1], dp[j-1][0]);
        }
    }

    cout<<dp[n][1];
    return 0;
}