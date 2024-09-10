#include <iostream>
#include <vector>
using namespace std;
vector<int> dp(1005);
int main(){
    int n; cin>>n;
    dp[1] = 0; dp[2] = 1; dp[3] = 0;
    for(int i=4;i<=n;i++){
        if(dp[i-1]==0 || dp[i-3]==0) dp[i] = 1;
    }
    cout<<(dp[n] ? "SK" : "CY");
    return 0;
}