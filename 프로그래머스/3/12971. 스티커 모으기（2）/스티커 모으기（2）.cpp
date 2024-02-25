#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    if(sticker.size() == 1) return sticker[0];
    int answer =0;
    int dp[100000+5];
    dp[0] = sticker[0];
    dp[1] = max(sticker[0], sticker[1]);
    for(int i=2;i<sticker.size()-1;i++){ //마지막 스티커는 안뗀다고 가정
        dp[i] = max(dp[i-2] + sticker[i], dp[i-1]);
    }
    answer = max(answer, dp[sticker.size()-2]);
    
    dp[0] = 0;
    dp[1] = sticker[1];
    for(int i=2;i<sticker.size();i++){ //첫번째 스티커는 안뗀다고 가정
        dp[i] = max(dp[i-2] + sticker[i], dp[i-1]);
    }
    answer = max(answer, dp[sticker.size()-1]);
    return answer;
}