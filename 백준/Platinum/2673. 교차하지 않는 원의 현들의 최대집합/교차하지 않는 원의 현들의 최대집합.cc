#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int SIZE = 100+1;
//start를 새로운 1번점으로 지정
vector<vector<int>> connect(SIZE, vector<int>(SIZE)), dp(SIZE, vector<int>(SIZE, -1));
int solve(int a, int b){
    if(a==b) return 0;
    
    int &ret = dp[a][b];
    if(ret != -1) return ret;
    dp[a][b] = 0;
    for(int k=a;k<b;k++){
        dp[a][b] = max(dp[a][b], solve(a,k) + solve(k+1,b) + connect[a][b]);
    }

    // printf("%d %d: %d\n", a,b,dp[a][b]);
    return ret;
}


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        connect[a][b] = connect[b][a] = 1;
    }
    
    cout<<solve(1, 100);
    return 0;
}