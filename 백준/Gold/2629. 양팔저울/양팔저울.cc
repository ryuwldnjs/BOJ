#include <iostream>
#include <vector>
#define BIAS 40000+500
using namespace std;

int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    int n; cin>>n;
    vector<int> arr(n);
    vector<vector<int>> dp(n, vector<int>(2*BIAS));
    for(auto &it: arr) cin>>it;

    dp[0][BIAS+0] = dp[0][BIAS-arr[0]] = dp[0][BIAS+arr[0]] = true;
    for(int i=1;i<n;i++){
        for(int j=0;j<2*BIAS;j++){
            if(j - arr[i]>=0 && dp[i-1][j - arr[i]]) dp[i][j] = true;
            if(                     dp[i-1][j]) dp[i][j] = true;
            if(j + arr[i]<2*BIAS && dp[i-1][j + arr[i]]) dp[i][j] = true;
        }
    } 
    // for(int i=0;i<2*BIAS;i++){
    //     if(dp[n-1][i]) printf("%d ", i-BIAS);
    // }

    int q; cin>>q;
    while(q--){
        int x; cin>>x;
        if(dp[n-1][BIAS + x]) cout<<"Y ";
        else cout<<"N ";
    }
    return 0;
}