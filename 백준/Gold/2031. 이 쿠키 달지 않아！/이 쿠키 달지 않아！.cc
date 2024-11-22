#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t,n,d,k, ans;
vector<int> arr, cnt;
vector<vector<int>> dp;//dp[i][j]: i번째음식까지, j개의 차를 마셨을때의 최대 횟수
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>t>>n>>d>>k;
    arr.resize(n), cnt.resize(n);
    dp = vector<vector<int>>(n, vector<int>(k+1));
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());
    for(int i=0;i<n;i++){
        int idx = upper_bound(arr.begin(), arr.end(), arr[i] - d) - arr.begin();
        cnt[i] = i - idx + 1;
        // printf("%d ", cnt[i]);
    }
// printf("\n");
    for(int j=1;j<=k;j++){
        for(int i=0;i<n;i++){
            if(i) dp[i][j] = dp[i-1][j];
            dp[i][j] = max(dp[i][j], cnt[i]);
            dp[i][j] = max(dp[i][j], dp[i][j-1]);
            int idx = upper_bound(arr.begin(), arr.end(), arr[i] - d) - arr.begin() - 1;
            if(idx >= 0){
                dp[i][j] = max(dp[i][j], dp[idx][j-1] + cnt[i]);
            }
            // printf("%d ", dp[i][j]);
            ans = max(ans, dp[i][j]);
        }
        // printf("\n");
    }

    cout<<ans;
    return 0;
}