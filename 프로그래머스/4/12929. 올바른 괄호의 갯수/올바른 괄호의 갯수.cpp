#include <bits/stdc++.h>
using namespace std;
int solution(int n) {
    vector<int> dp(15, 1);
    for(int i=2;i<=n;i++) dp[i] = dp[i-1] * (4*i-2)/(i+1);
    return dp[n];
}