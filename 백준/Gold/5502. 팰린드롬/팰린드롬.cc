#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 1e9;
int n;
vector<char> a;
int dp[5005][5005];
//[l,r]구간을 팰린드롬으로 만드는데 드는 비용
int solve(int l, int r){
    if(l >= r) return 0;

    int &ret = dp[l][r];
    if(ret != INF) return ret;

    if(a[l] == a[r]) ret = min(ret, solve(l+1, r-1));
    else{
        ret = min(ret, solve(l+1, r) + 1); 
        ret = min(ret, solve(l, r-1) + 1); 
    }

    return ret;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    a.resize(n);
    fill(&dp[0][0], &dp[5004][5004], INF);

    for(int i=0;i<n;i++) cin>>a[i];
    
    cout<<solve(0, n-1);
    return 0;
}