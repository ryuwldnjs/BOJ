#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define RIGHT 0
#define DOWN 1

const int MOD = 100000;
int dp[105][105][2];
//dp[i][j][dir]: (i,j)에 dir방향으로 왔을때,
//dir: 0=동쪽, 1=남쪽
int w,h;
int solve(int y, int x, int dir){
    if(y>h || x>w) return 0;
    if(y==h && x==w) return 1;
    int &ret = dp[y][x][dir];
    if(ret != -1) return ret;
    ret = 0;

    //좌우 이동
    if(dir==RIGHT) ret += solve(y,x+1,RIGHT) + solve(y+1, x+1, DOWN);
    //상하 이동
    else ret += solve(y+1, x, DOWN) + solve(y+1, x+1, RIGHT);
    ret %= MOD;
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    fill(&dp[0][0][0], &dp[104][104][1], -1);
    cin>>w>>h;
    cout<<(solve(1,1,RIGHT) + solve(1,1,DOWN)) % MOD;

    return 0;
}