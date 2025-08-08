#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 1e9;
vector<vector<int>> dp;
vector<int> a,b;
int solve(int i, int j){
    if(i < 0 || j < 0) return 0;
    int &ret = dp[i][j];
    if(ret != INF) return ret;

    if(i == j) ret = solve(i-1, j-1) + abs(a[i] - b[j]);
    if(i > j) ret = min(solve(i-1, j-1) + abs(a[i] - b[j]), solve(i-1, j));
    if(i < j) ret = min(solve(i-1, j-1) + abs(a[i] - b[j]), solve(i, j-1));
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,m;cin>>n>>m;
    dp.resize(n, vector<int>(m, INF));
    a.resize(n);
    b.resize(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    cout<<solve(n-1, m-1);
    return 0;
}