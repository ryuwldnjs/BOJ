#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 1e9;
int n,m;
vector<vector<int>> a,psum;
int getPsum(int y1, int x1, int y2, int x2){
    return psum[y2][x2] - psum[y1-1][x2] - psum[y2][x1-1] + psum[y1-1][x1-1];
}

//열 [x1, x2]를 고정시켰을때, 부분행렬 최댓값
int getMAX(int x1, int x2){
    vector<int> dp(n+1);
    int MAX = -INF;
    for(int y=1;y<=n;y++){
        dp[y] = max(dp[y-1] + getPsum(y, x1, y, x2), getPsum(y, x1, y, x2));
        MAX = max(MAX, dp[y]);
    }
    // printf("%d %d: %d\n", x1, x2, MAX);
    return MAX;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    a.resize(n+1, vector<int>(m+1));
    psum.resize(n+1, vector<int>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            psum[i][j] = a[i][j] + psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
        }
    }

    int answer = -INF;
    for(int x1=1;x1<=m;x1++){
        for(int x2=x1;x2<=m;x2++){
            answer = max(answer, getMAX(x1, x2));
        }
    }

    cout<<answer;
    return 0;
}