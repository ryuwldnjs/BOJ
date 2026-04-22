#include <string>
#include <vector>
#define MOD 1000000007

using namespace std;
int dp[100000+5];
int solution(int n, vector<int> money) {
    int answer = 0;
    dp[0] = 1;
    
    for(int m: money){ //m종류까지만 썼을때 해당 금액을 몇가지 만들수있는가
        for(int i=0;i<=n;i++){
            if(i-m>=0) dp[i] += dp[i - m];
        }
    }
    return dp[n];
}