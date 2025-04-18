#include <iostream>
using namespace std;
const int SIZE = 10000;
int dp[4][SIZE+1];
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t;

    for(int i=0;i<=SIZE;i++) dp[1][i] = 1;
    dp[2][0] = 1; dp[3][0] = 1;
    
    for(int i=2; i<=3;i++){
        for(int j=1; j<=SIZE; j++){
            dp[i][j] = dp[i-1][j];
            if(j-i >= 0) dp[i][j] += dp[i][j-i];
        }
    }

    while(t--){
        int k; cin>>k;
        cout<<dp[3][k]<<'\n';
    }
    return 0;
}