#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n,m;
int psum[505][505];
int dp_up[505][505][505];
int dp_down[505][505][505];
//dp[c1][c2][r]: 좌우[c1,c2]구간에서, 부분 r행을 포함하는 최대 구간합
//닫힌범위

int getPsum(int y1, int x1, int y2, int x2){
    return psum[y2][x2] - psum[y1-1][x2] - psum[y2][x1-1] + psum[y1-1][x1-1];
}
void printAnswer(int y){
    int dp[505][505];//[c1][c2]구간

    for(int c1=1; c1<=m; c1++){
        for(int c2=c1; c2<=m; c2++){
            int val = dp_up[c1][c2][y] + dp_down[c1][c2][y] - getPsum(y, c1 ,y, c2);
            dp[c1][c2] = val;
        }
    }   

    //최댓값을 가지는 (L, R) 구간의 상태를 더 좁은 범위로 상태 전이
    for(int gap=m;gap>=0;gap--){
        for(int i=1;i<=m;i++){
            int l = i;
            int r = i + gap;
            if(l-1>=1) dp[l][r] = max(dp[l][r], dp[l-1][r]);
            if(r+1<=m) dp[l][r] = max(dp[l][r], dp[l][r+1]);
        }
    }

    for(int i=1;i<=m;i++){
        cout<<dp[i][i]<<' ';
    }

    return;
}



int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;

    int board[505][505];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>board[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            psum[i][j] = board[i][j] + psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
        }
    }


    //좌우 범위 고정했을때
    for(int c1=1;c1<=m;c1++){
        for(int c2=c1;c2<=m;c2++){
            for(int r=1;r<=n;r++){
                dp_up[c1][c2][r] = 
                    max(dp_up[c1][c2][r-1] + getPsum(r, c1, r, c2)
                        , getPsum(r, c1, r, c2));
            }

            for(int r=n;r>=1;r--){
                dp_down[c1][c2][r] = 
                    max(dp_down[c1][c2][r+1] + getPsum(r, c1, r, c2)
                        , getPsum(r, c1, r, c2));
            }
        }
    }

    for(int i=1;i<=n;i++){
        printAnswer(i);
        cout<<'\n';
    }
    return 0;
}