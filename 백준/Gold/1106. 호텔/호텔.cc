#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int SIZE = 1000000;
const int INF = 1e9;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int c,n;cin>>c>>n;
    vector<int> cost(n),value(n), dp(SIZE, INF);
    for(int i=0;i<n;i++){
        cin>>cost[i]>>value[i];
    }

    dp[0] = 0;
    for(int j=0;j<SIZE;j++){
        for(int i=0;i<n;i++){
            if(j - value[i] >= 0) dp[j] = min(dp[j], dp[j - value[i]] + cost[i]);
        }
    }
    int answer = INF;
    for(int j=c;j<SIZE;j++){
        answer = min(answer, dp[j]);
        // printf("%d\n", dp[j]);
    }

    cout<<answer;
    return 0;
}