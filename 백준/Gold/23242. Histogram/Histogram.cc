#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const double INF = 1e17;
ll B,n;
double f[4005], psumX[4005], psumX2[4005];
double V[4005][4005];

double dp[35][4005];
//dp[b][n] = MIN{ dp[b-1][j] + V[j+1][n] }
int main(){
    scanf("%lld %lld", &B, &n);
    for(int i=1;i<=n;i++) scanf("%lf", &f[i]);

    for(int i=1;i<=n;i++){
        psumX[i] = psumX[i-1] + f[i];
        psumX2[i] = psumX2[i-1] + f[i]*f[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            ll cnt = j - i + 1;
            //V[x] = 편차제곱의 총량으로 정의 ; 나누기 n에 다시 곱하기 n
            double EX2 = (psumX2[j] - psumX2[i-1]) / cnt;
            double EX = (psumX[j] - psumX[i-1]) / cnt;
            V[i][j] = (EX2 - EX*EX) * cnt;
        }
    }



    fill(&dp[0][0], &dp[34][4004], INF);
    dp[0][0] = 0;

    for(int i=1;i<=B;i++){
        dp[i][0] = 0;
        for(int r=1;r<=n;r++){
            for(int l=0;l<r;l++){
                dp[i][r] = min(dp[i][r], dp[i-1][l] + V[l+1][r]);
            }

            // printf("%lf\n", dp[i][r]);
        }
        // printf("\n");
    }



    printf("%.06lf", dp[B][n]);
    
    return 0;
}