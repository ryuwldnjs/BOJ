#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;


// dp[i][b][w] : i번쨰 사람까지 중 b명, w명 조합으로 구한 최댓값
// dp[i][b][w] = MAX {dp[i][b][w], dp[i-1][b-1][w] + b[i], dp[i-1][b][w-1] + w[i] }

int b[1005], w[1005];
int dp[1005][20][20];

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    int answer = 0;
    for(int idx=1; cin>>b[idx]>>w[idx];idx++){
        for(int i=0;i<=15;i++){
            for(int j=0;j<=15;j++){
                dp[idx][i][j] = dp[idx-1][i][j];
                if(i) dp[idx][i][j] = max(dp[idx][i][j], dp[idx-1][i-1][j] + b[idx]);
                if(j) dp[idx][i][j] = max(dp[idx][i][j], dp[idx-1][i][j-1] + w[idx]);
                
                answer = max(answer, dp[idx][i][j]);
            }
        }
    }

    cout<<answer;
    return 0;
}