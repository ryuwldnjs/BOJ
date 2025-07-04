#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int n;
void track(vector<int> &arr,vector<vector<bool>> &dp){
    int val = 0;
    vector<int> answer;
    int idx=100;
    while(dp[idx-1][val]) idx--;
    // printf("%d\n",idx);

    for(;idx>0;idx--){
        // printf("%d,%d: %d\n", idx, val, dp[idx-1][val]? 1: 0);
        if(!dp[idx][val] || dp[idx-1][val]) answer.push_back(0);
        else{
            answer.push_back(1);
            val = (val - arr[idx] + n*n) % n;
        }
    }

    for(int i:answer) cout<<i;
    cout<<'\n';
}
void solve(){
    vector<int> arr(101);
    vector<vector<bool>> dp;
    cin>>n;
    dp.resize(101, vector<bool>(n+10));
    //dp[i][val] : 1~ 10^i까지 숫자중 조합해서 val을 만들수있는가
    // dp[0][0] = true;
    int remain = 1;
    for(int i=1;i<=100;i++){
        // printf("%d\n", remain);
        arr[i] = remain;
        dp[i][(remain)%n] = true;
        remain = (remain*10) % n;
    }

    for(int i=1;i<=100;i++){
        for(int j=0;j<n+10;j++){
            dp[i][j] = dp[i][j] || dp[i-1][j];
            dp[i][j] = dp[i][j] || dp[i-1][(j - arr[i] + n*n) % n];
        }
    }

    // cout<<dp[99][0]<<'\n';
    // printf("\n");

    if(!dp[100][0]) cout<<"BRAK\n";
    else track(arr, dp);
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}