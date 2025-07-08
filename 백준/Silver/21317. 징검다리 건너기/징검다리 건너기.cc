#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 1e9;

int n,k;
vector<vector<int>> dp;
vector<int> jump1, jump2;
//dp[i][s]: 지금깢 s번 슈퍼점프하고, i번째 돌까지 오는데에 최솟값
//s는 0 or 1
int solve(int idx, int s){
    if(idx == 1) return 0;

    int &ret = dp[idx][s];
    if(ret != INF) return ret;
    // ret = 0;

    //지금까지 슈퍼점프를 안했을때
    if(s == 0){
        if(idx-1 >= 1) ret = min(ret, jump1[idx-1] + solve(idx-1, 0));
        if(idx-2 >= 1) ret = min(ret, jump2[idx-2] + solve(idx-2, 0));
    }
    //지금까지 슈퍼점프를 했을때
    else{
        if(idx-1 >= 1) ret = min(ret, jump1[idx-1] + solve(idx-1, 1));
        if(idx-2 >= 1) ret = min(ret, jump2[idx-2] + solve(idx-2, 1));
        if(idx-3 >= 1) ret = min(ret, k + solve(idx-3, 0));
    }
    // printf("%d,%d:%d\n",idx,s,dp[idx][s]);
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    jump1.resize(n+1);
    jump2.resize(n+1);
    dp.resize(n+1, vector<int>(2, INF));

    for(int i=1;i<n;i++){
        cin>>jump1[i]>>jump2[i];
    }
    cin>>k;

    cout<<min(solve(n, 0), solve(n, 1));
    return 0;
}