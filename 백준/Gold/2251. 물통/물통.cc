#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int A,B,C;
bool dp[205][205][205];
void dfs(int a, int b, int c){
    bool &ret = dp[a][b][c];
    if(ret) return;
    // printf("%d %d %d\n", a,b,c);
    ret = true;
    
    //a를 b or c에 투하
    dfs( max(0, a+b - B), min(B, a+b), c );
    dfs( max(0, a+c - C), b, min(C, a+c) );

    //b를 a or c에 투하
    dfs(min(A, b+a) , max(0, b+a - A),  c);
    dfs(a , max(0, b+c - C), min(C, b+c));

    //c를 a or b에 투하
    dfs(min(A, c+a) , b, max(0, c+a - A));
    dfs(a, min(B, c+b), max(0, c+b - B));
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>A>>B>>C;
    
    dfs(0, 0, C);

    for(int i=C-B; i<=C;i++){
        // printf("%d %d: ", C-i, i);
        if(dp[0][C-i][i]) cout<<i<<' ';
    }
    return 0;
}