#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;

vector<pii> ban[105][105];
ll dp[105][105]={1,};
//[x1,y1] -> [x2,y2]로 가는 길이 있는지
bool pass(ll x1, ll y1, ll x2, ll y2){
    vector<pii> banned = ban[x1][y1];
    if(count(banned.begin(), banned.end(), make_pair(x2,y2))) return false;
    return true;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n,m,k;cin>>n>>m;
    cin>>k;
    for(ll i=0;i<k;i++){
        ll x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        ban[x1][y1].push_back({x2,y2});
        ban[x2][y2].push_back({x1,y1});
    }

    

    for(ll i=1;i<=n;i++){
        if(pass(i-1, 0, i, 0)) dp[i][0] = dp[i-1][0];
    }
    for(ll i=1;i<=m;i++){
        if(pass(0, i-1, 0, i)) dp[0][i] = dp[0][i-1];
    }

    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(pass(i-1,j,i,j)) dp[i][j] += dp[i-1][j];
            if(pass(i,j-1,i,j)) dp[i][j] += dp[i][j-1];
        }
    }

    cout<<dp[n][m];
    return 0;
}