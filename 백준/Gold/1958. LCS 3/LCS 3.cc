#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

string str[3];
int dp[105][105][105];

int solve(int a, int b, int c){
    memset(dp, -1, sizeof(dp));
    
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            for(int k=0;k<c;k++){
                if(i*j*k == 0){ // 0개 일치 정의
                    dp[i][j][k] = 0;
                    continue;
                }

                dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);
                dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k]);
                dp[i][j][k] = max(dp[i][j][k], dp[i][j][k-1]);
                if(str[0][i]==str[1][j] && str[1][j]==str[2][k]) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k-1] + 1);
            }
        }
    }
    return dp[a-1][b-1][c-1];
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    for(int i=0;i<3;i++){
        cin>>str[i];
        str[i] = "#" + str[i];
    }

    cout<<solve(str[0].size(), str[1].size(), str[2].size());
    return 0;
}