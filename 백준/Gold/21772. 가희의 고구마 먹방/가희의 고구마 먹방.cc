#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};
int r,c,t;
char board[105][105];
// bool isEaten[105][105];
bool pass(int y, int x){
    return 0<=y&&y<r && 0<=x&&x<c && board[y][x] != '#';
}


int solve(int y, int x, int move){
    int ret = 0;
    if(move >= t) return 0;

    for(int i=0;i<4;i++){
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(!pass(yy,xx)) continue;

        if(board[yy][xx] == 'S'){
            board[yy][xx] = '.';
            ret = max(ret, solve(yy, xx, move+1) + 1);
            board[yy][xx] = 'S';
        }
        else{
            ret = max(ret, solve(yy, xx, move+1));
        }
    }

    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>r>>c>>t;

    int sy,sx;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>board[i][j];
            if(board[i][j] == 'G'){
                sy = i;
                sx = j;
            }
        }
    }

    cout<<solve(sy, sx, 0);


    return 0;
}