#include <iostream>
#include <vector>
using namespace std;
vector<int> arr,dp;// dp[i]: 0~i번째 학생을 가지고, 최대 점수
vector<vector<int>> gaps;
int n;
int main(){
    cin>>n;
    arr.resize(n);
    dp.resize(n);
    gaps.resize(n, vector<int>(n));
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        int MAX=-1e9;
        int MIN=1e9;
        // for(int j=0;j<i;j++) printf("0 ");
        for(int j=i;j<n;j++){
            MAX = max(MAX, arr[j]);
            MIN = min(MIN, arr[j]);
            gaps[i][j] = MAX - MIN;
            // printf("%d ", gaps[i][j]);
        }
        // printf("\n");   
    }
    
    for(int i=0;i<n;i++){
        dp[i] = gaps[0][i];
        for(int j=1;j<i;j++){// [0,j] / [j+1, i]두개로 쪼갬
            dp[i] = max(dp[i], dp[j] + gaps[j+1][i]);
        }
        // printf("%d ", dp[i]);
    }
    cout<<dp[n-1];
    return 0;
}