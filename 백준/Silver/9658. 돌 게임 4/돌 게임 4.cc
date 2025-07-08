#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
vector<int> dp;
bool solve(int n){
    if(n == 1) return false;
    if(n < 1) return true;

    int &ret = dp[n];
    if(ret != -1) return ret;

    ret = !solve(n-1) || !solve(n-3) || !solve(n-4);
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    dp.resize(n+1, -1);
    if(solve(n)) cout<<"SK";
    else cout<<"CY";
    return 0;
}