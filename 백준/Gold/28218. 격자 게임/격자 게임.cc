#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
vector<vector<int>> dp;
vector<vector<char>> a;
int n,m,k;

bool pass(int y, int x){
    return 1<=y&&y<=n && 1<=x&&x<=m && a[y][x] =='.';
}

//dp[y][x]: (y,x)가 시작점일때 승리할수있는가
int solve(int y, int x){
    if(y==n && x==m) return 0;
    int &ret = dp[y][x];
    if(ret != -1) return ret;
    ret = 0;

    
    if(pass(y+1, x)) ret = max(ret, (int)!solve(y+1, x));
    if(pass(y, x+1)) ret = max(ret, (int)!solve(y, x+1));
    for(int i=1;i<=k;i++){
        if(pass(y+i, x+i)) ret = max(ret, (int)!solve(y+i, x+i));
    }
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m>>k;
    a.resize(n+1, vector<char>(m+1));
    dp.resize(n+1, vector<int>(m+1, -1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    
    int q;cin>>q;
    while(q--){
        int y,x;cin>>y>>x;
        if(solve(y,x)) cout<<"First\n";
        else cout<<"Second\n";
    }
    return 0;
}