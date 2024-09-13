#include <iostream>
#include <vector>
#include <string>
#define MOD 1000000
using namespace std;
vector<int> arr, dp(5000+5);
// dp[i] : i번째 자리까지의 가능한 해석 수
// do[i] = dp[i-1];
// dp[i] = do[i-2] + dp[i-1]  (단, 제일 우측 두자리가 가능한숫자라면 10~26)
int main(){
    string tmp; cin>>tmp;
    for(char x : tmp){
        arr.push_back(x - '0');
    }
    if(arr[0] == 0){
        cout<<0;
        return 0;
    }

    dp[0] = 1;
    if(arr[1] != 0) dp[1] = 1;
    int init2Num = arr[0]*10 + arr[1];
    if(10 <= init2Num&&init2Num <= 26){
        dp[1]++;
    }
    

    for(int i=2;i<arr.size();i++){
        int last2Num = arr[i-1]*10 + arr[i];
        int last1Num = arr[i];
        if(10 <= last2Num&&last2Num <= 26){
            dp[i] += dp[i-2];
            dp[i] %= MOD;
        } 
        if(1 <= last1Num&&last1Num <= 9){
            dp[i] += dp[i-1];
            dp[i] %= MOD;
        }
    }
    cout<<dp[arr.size()-1];
    return 0;
}