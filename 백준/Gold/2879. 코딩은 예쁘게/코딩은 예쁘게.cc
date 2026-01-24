#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define INF 1e9

int n;
int a[1005], b[1005];
int dp[1005][1005]; //[l,r]구간의 편집 횟수 최솟값
int rangeChance[1005][1005]; //[l,r]구간에 적용가능한 커맨드 횟수

int solve(int l, int r){
    if(l > r) return INF;
    if(l == r) return abs(b[l] - a[l]);

    int &ret = dp[l][r];
    if(ret != -1) return ret;

    ret = INF;

    // [l, i], [i+1, r]
    for(int i=l;i<r;i++){
        ret = min(ret, solve(l,i) + solve(i+1,r) - rangeChance[l][r]);
    }
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    memset(dp, -1, sizeof(dp));

    cin>>n;

    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    for(int i=0;i<n;i++){
        int MAX = -INF;
        int MIN = INF;
        for(int j=i;j<n;j++){
            MAX = max(MAX, b[j] - a[j]);
            MIN = min(MIN, b[j] - a[j]);
            
            //서로 동일한 커맨드로 가능할떄만
            if(MAX * MIN > 0){
                rangeChance[i][j] = min(abs(MAX), abs(MIN));
            }
        }
  
    }

    cout<<solve(0, n-1);
    return 0;
}