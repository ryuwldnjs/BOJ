#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 1e9;
int dp[10000+5][100+5];

int solve(int n,int m){
    if(n < m) swap(n, m);
    if(n==0 || m == 0) return 0;
    if(n % m == 0) return n/m;

    if(n == m) return 1;

    int &ret = dp[n][m];
    if(ret != -1) return ret;

    ret = n*m;
    
    if(n >= 3*m){
        return ret = min(ret, solve(n-m, m) + 1);
    }
    
    for(int k=1;k<=n/2;k++){
        ret = min(ret, solve(n-k, m) + solve(k,m));
    }
    for(int k=1;k<=m/2;k++){
        ret = min(ret, solve(n,m-k) + solve(n,k));
    }


    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,m;cin>>n>>m;

    memset(dp, -1, sizeof(dp));
    cout<<solve(n,m);
    return 0;
}