#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define INF 1e9

int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

vector<vector<char>> board;

bool isMelted(int y, int x){
    int cnt = 0;
    for(int i=0;i<4;i++){
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(board[yy][xx] == '.') cnt++;
    }
    return cnt >= 3;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int r,c;cin>>r>>c;
    board.resize(r+2, vector<char>(c+2, '.'));

    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>board[i][j];
        }
    }

    auto tmp = board;

    int y1=INF, y2=-INF;
    int x1=INF, x2=-INF;

    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(board[i][j] == 'X' && isMelted(i,j)) tmp[i][j] = '.';
            if(tmp[i][j] == 'X'){
                y1 = min(y1, i);
                y2 = max(y2, i);
                x1 = min(x1, j);
                x2 = max(x2, j);
            }
        }
    }

    // printf("%d,%d %d,%d\n", y1,x1, y2,x2);
    for(int i=y1;i<=y2;i++){
        for(int j=x1;j<=x2;j++){
            cout<<tmp[i][j];
        }
        cout<<'\n';
    }
    return 0;
}