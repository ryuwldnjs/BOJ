#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<vector<int>> dp(2550, vector<int>(2550, -1));
int solution(string s){
    int answer = 0;
    for(int i=1;i<=s.size();i++){
        for(int j=i-1;j<s.size();j++){
            int l=j-i+1, r=j;
            if(s[l] == s[r] && (r-l<=1 || dp[l+1][r-1] != -1)) dp[l][r] = r - l + 1;
            answer = max(answer, dp[l][r]);
        }
    }
    return answer;
}