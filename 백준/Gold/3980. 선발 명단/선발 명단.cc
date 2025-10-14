#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 1e5;
//dp[i][bit]:i번째 사람까지중에서 bit조합의 포지션일때의 최댓값
// dp[i][bit] = 
void solve(){
    int a[12][12];
    int dp[12][1<<11];
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int i=1;i<=11;i++){
        for(int j=0;j<11;j++){
            cin>>a[i][j];
            if(a[i][j] == 0) continue;
            for(int bit=0;bit<(1<<11);bit++){
                if(bit & (1<<j) || dp[i-1][bit] == -1) continue; //j포지션을 아직 안고른것들중에서만
                dp[i][bit | (1<<j)] = max(dp[i][bit | (1<<j)], dp[i-1][bit] + a[i][j]);
            }
        }
    }

    cout<<dp[11][(1<<11) - 1]<<'\n';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}