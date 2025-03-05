#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;

int n,w;
int solve(vector<vector<int>>&arr){
    vector<vector<int>> dp(3, vector<int>(n, INF));
    dp[0][0] = 1; dp[1][0] = 1;

    if(arr[0][0]+arr[1][0] <= w) dp[2][0] = 1;
    else dp[2][0] = 2;


    for(int i=1;i<n;i++){
        dp[0][i] = dp[2][i-1] + 1;
        if(arr[0][i]+arr[0][i-1] <= w) dp[0][i] = min(dp[0][i], dp[1][i-1] + 1);

        dp[1][i] = dp[2][i-1] + 1;
        if(arr[1][i]+arr[1][i-1] <= w) dp[1][i] = min(dp[1][i], dp[0][i-1] + 1);

        dp[2][i] = dp[2][i-1] + 2;
        if(arr[0][i]+arr[1][i] <= w) dp[2][i] = dp[2][i-1] + 1;
        if(arr[0][i]+arr[0][i-1] <= w) dp[2][i] = min(dp[2][i], dp[1][i-1] + 2);
        if(arr[1][i]+arr[1][i-1] <= w) dp[2][i] = min(dp[2][i], dp[0][i-1] + 2);
        //1,2번라인 각각 가로로 2개 묶을수있을때
        if(arr[0][i]+arr[0][i-1] <= w && arr[1][i]+arr[1][i-1] <= w){
            if(i==1) dp[2][i] = 2;
            else dp[2][i] = min(dp[2][i], dp[2][i-2] + 2);
        }
        // cout<<dp[0][i]<<' '<<dp[1][i]<<' '<<dp[2][i]<<'\n';
    }

    return dp[2][n-1];
}

//인터페이스
void solve(){
    cin>>n>>w;
    vector<vector<int>> arr(2, vector<int>(n));
    for(auto &i : arr[0]) cin>>i;
    for(auto &i : arr[1]) cin>>i;
    
    
    int answer = solve(arr);
    
    if(n<=2){ // 양끝 연결이 없어도 되는 경우
        cout<<answer<<'\n';
        return;
    }
    
    int a_l = arr[0][0], a_r = arr[0][n-1];
    int b_l = arr[1][0], b_r = arr[1][n-1];

    /**
     * 양끝이 결합될 여지가 있으면, 다른곳과 결합되지 못하도록 최댓값으로 채우고, 양끝이 결합되었다고 가정하기
     */
    if(arr[0][0]+arr[0][n-1] <= w && arr[1][0]+arr[1][n-1] <= w){
        arr[0][0] = arr[0][n-1] = arr[1][0] = arr[1][n-1] = w;
        answer = min(answer, solve(arr) - 2);// 1,2번라인 각각 양끝이 연결됨
        arr[0][0] = a_l; arr[0][n-1] = a_r;
        arr[1][0] = b_l; arr[1][n-1] = b_r;
    } 
    if(arr[0][0]+arr[0][n-1] <= w){
        arr[0][0] = arr[0][n-1] = w;
        answer = min(answer, solve(arr) - 1); // 1번라인의 양끝이 연결됨
        arr[0][0] = a_l; arr[0][n-1] = a_r;
    } 
    if(arr[1][0]+arr[1][n-1] <= w){
        arr[1][0] = arr[1][n-1] = w;
        answer = min(answer, solve(arr) - 1); // 2번라인의 양끝이 연결됨
        arr[1][0] = b_l; arr[1][n-1] = b_r;
    } 
    
    cout<<answer<<'\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}