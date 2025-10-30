#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const ll INF = 1e15;
ll dp[2005][2005];
ll arr[2005];
ll n;
//dp[a][b] : 각자 마지막으로 부른 위치가 a,b일때의 최소비용

ll getCost(int l, int r){
    if(l == 0) return 0;
    return abs(arr[l] - arr[r]);
}

ll solve(int a, int b){
    int next = max(a,b) + 1;
    if(next > n) return 0;
    
    ll &ret = dp[a][b];
    if(ret != -1) return ret;
    ret = INF;

    ret = min(ret, solve(next, b) + getCost(a, next));
    ret = min(ret, solve(a, next) + getCost(b, next));
    return ret;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];


    memset(dp, -1, sizeof(dp));
    cout<<solve(0,0);
    return 0;
}