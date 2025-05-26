#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

//13개 = 1 + 2 + 4 + 6으로 분할
vector<int> value, weight;
vector<vector<int>> dp;
void partition(int v, int c, int k){
    int cnt = 1;
    while(cnt <= k){
        weight.push_back(v * cnt);
        value.push_back(c * cnt);
        k -= cnt;
        cnt *= 2;
    }
    if(k > 0){
        weight.push_back(v * k);
        value.push_back(c * k);
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        int v,c,k;cin>>v>>c>>k;
        partition(v, c, k);
    }

    dp.resize(value.size(), vector<int>(m+1));
    for(int j=0;j<=m;j++){
        if(j - weight[0] >= 0) dp[0][j] = value[0];
    }
    //분할된 물건들
    for(int i=1;i<value.size(); i++){
        for(int j=0;j<=m;j++){
            dp[i][j] = dp[i-1][j];
            if(j - weight[i] >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j - weight[i]] + value[i]);
        }
    }
    cout<<dp.back().back();//dp[SIZE][M]
    return 0;
}