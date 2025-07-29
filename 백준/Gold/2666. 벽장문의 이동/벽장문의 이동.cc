#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 1e9;
int dp[25][25][25];
//it번째 순서에서 문이 (i,j)위치이고 it번째 값을 포함할대의 일때의 비용
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    fill(&dp[0][0][0], &dp[24][24][24], INF);

    int n,a,b,m;
    cin>>n>>a>>b;
    cin>>m;
    
    if(a>b) swap(a,b);
    dp[0][a][b] = 0;


    for(int it=1;it<=m;it++){
        int target; cin>>target;

        for(int i=1;i<=n;i++){
            int a = target;
            int b = i;
            if(a > b) swap(a,b);

            for(int j=1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    dp[it][a][b] = min(dp[it][a][b], dp[it-1][j][k] + abs(a-j) + abs(b-k));
                }
            }
        }
    }

    int answer = INF;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            answer = min(answer, dp[m][i][j]);
        }
    }

    cout<<answer;
    return 0;
}