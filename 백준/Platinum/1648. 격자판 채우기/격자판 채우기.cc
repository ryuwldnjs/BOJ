#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int MOD = 9901;

vector<vector<int>> dp;
int n,m;

int solve(int idx, int bit){
    if(idx == n*m && bit == 0) return 1;
    if(idx >= n*m) return 0;

    int &ret = dp[idx][bit];
    if(ret != -1) return ret;
    ret = 0;


    if(bit & 1) ret += solve(idx+1, bit>>1);
    else{
        //가로
        //행 끝이 아니면서, 우측 한칸이 비어있을때
        if(idx%m != m-1 && (bit & 1<<1) == 0){
            ret += solve(idx+2, bit>>2);
            ret %= MOD;
        }
        //세로
        ret += solve(idx+1, (bit>>1) | (1<<(m-1)));
        
    }
    return ret % MOD;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    dp.resize(15*15, vector<int>(1<<15, -1));

    cout<<solve(0, 0);
    return 0;
}