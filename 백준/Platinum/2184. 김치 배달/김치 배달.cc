#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;
const ll INF = 1e17;

ll n, L;
vector<ll> pos;
ll dp[1005][1005][2]; //최소거리
//dp[l][r][last]
//dp[l][r][0] : [l, r]구간에 대해 l에서 끝난 상태일때의 최솟값
//dp[l][r][1] : [l, r]구간에 대해 r에서 끝난 상태일때의 최솟값

//dp[l][r][0] = min(dp[l+1][r][0] + (pos[l+1]-pos[l])*남은김치, dp[l+1][r][1] + (pos[r]-pos[l]) * 남은김치)
//dp[l][r][1] = min(dp[l][r-1][1] + (pos[r]-pos[r-1])*남은김치, dp[l][r-1][0] + (pos[r]-pos[l]) * 남은김치)

ll solve(ll l, ll r, ll last){
    if(l > r) return INF;
    
    ll &ret = dp[l][r][last];
    if(ret != -1) return ret;
    ret = INF;
    ll remain = n - (r-l);
    if(last == 0)
        ret = min(solve(l+1, r, 0) + (pos[l+1]-pos[l]) * remain, solve(l+1, r, 1) + (pos[r] - pos[l])*remain);

    else
        ret = min(solve(l, r-1, 1) + (pos[r] - pos[r-1]) * remain, solve(l, r-1, 0) + (pos[r] - pos[l])*remain);
    
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>L;
    pos.resize(n);
    
    for(ll i=0;i<n;i++) cin>>pos[i];
    sort(pos.begin(), pos.end());
   
    fill(&dp[0][0][0], &dp[1004][1004][1], -1);

    ll idx = lower_bound(pos.begin(), pos.end(), L) - pos.begin();
    
    if(pos[n-1] <= L){
        dp[n-1][n-1][0] = dp[n-1][n-1][1] = (L - pos[n-1]) * n;
    }
    else if(L <= pos[0]){
        dp[0][0][0] = dp[0][0][1] = (pos[0] - L) * n;
    }
    else{
        dp[idx][idx][0] = dp[idx][idx][1] = (pos[idx] - L) * n;
        if(pos[idx] != L) dp[idx-1][idx-1][0] = dp[idx-1][idx-1][1] = (L - pos[idx-1]) * n;
    }

    cout<<min(solve(0, n-1, 0), solve(0, n-1, 1));
    return 0;
}