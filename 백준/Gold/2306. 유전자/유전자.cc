#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
map<char, char> match;

string a;
int n;

int dp[505][505];
int solve(int l, int r){
    if(l >= r) return 0;


    int &ret = dp[l][r];
    if(ret != -1) return ret;

    ret = solve(l+1, r-1) + (match[a[l]] == a[r] ? 2 : 0);

    for(int k=l; k<r;k++){
        ret = max(ret, solve(l, k) + solve(k+1, r));
    }
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>a;
    n = a.size();
    match['a'] = 't';
    match['g'] = 'c';

    memset(dp, -1, sizeof(dp));
    cout<<solve(0, n-1);
    return 0;
}