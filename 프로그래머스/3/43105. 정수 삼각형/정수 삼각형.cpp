#include <bits/stdc++.h>
using namespace std;
int dp[505][505];

int solution(vector<vector<int>> triangle) {
    dp[0][0] = triangle[0][0];
    for(int i=1;i<triangle.size();i++){
        
        for(int j=0;j<triangle[i].size();j++){
            dp[i][j] = max(j ? dp[i-1][j-1] : 0, dp[i-1][j]) + triangle[i][j];
        }
    }
    return *max_element(dp[triangle.size()-1], dp[triangle.size()-1] + triangle.size());
}