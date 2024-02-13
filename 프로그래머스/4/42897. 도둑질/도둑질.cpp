#include <bits/stdc++.h>

using namespace std;
int dp[2][1000000+5]; //dp[start][i] : start인덱스 시작일때
int solution(vector<int> money) {
    int n = money.size();
    dp[0][0] = dp[0][1] = money[0];
    dp[1][1] = money[1];
    
    for(int i=2;i<n;i++){
        dp[0][i] = max(dp[0][i-1], dp[0][i-2] + money[i]);
        dp[1][i] = max(dp[1][i-1], dp[1][i-2] + money[i]);
    }
    return max(dp[1][n-1], dp[0][n-2]);
}