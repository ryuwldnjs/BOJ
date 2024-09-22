#include <iostream>
#include<vector>
#define INF 1e9
using namespace std;

int n;
int work[22][22];
vector<vector<int>> dp(22, vector<int>(1<<20, INF)); // dp[i][bit] : i번째 사람까지 {bit}배열로 일했을때의 최솟값 
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>work[i][j];
        }
    }

    for(int i=0;i<n;i++) dp[0][1<<i] = work[0][i]; // base case
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            for(int bit=0;bit<(1<<n);bit++){
                if(bit & (1<<j)){
                    bit += (1<<j) - 1;
                    continue;
                }

                dp[i][(1<<j)|bit] = min(dp[i][(1<<j)|bit], dp[i-1][bit] + work[i][j]);
            }
        }
    }
    cout<<dp[n-1][(1<<n)-1];
    return 0;
}