#include <iostream>
using namespace std;
int n, dp[1000+5];
int main(){
    dp[1] = 1;
    dp[2] = 0;
    dp[3] = 1;
    dp[4] = 1;
    cin>>n;
    for(int i=5;i<1000+5;i++){
        if(dp[i-1] == 0) dp[i] = 1;
        if(dp[i-3] == 0) dp[i] = 1;
        if(dp[i-4] == 0) dp[i] = 1;
    }

    cout<<(dp[n] ? "SK" : "CY");
    return 0;
}