#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};
int n,m;
vector<vector<int>> board, b;

bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<m;
}

void dfs(int y, int x, int from, int to, vector<vector<int>> &a){
    a[y][x] = to;

    for(int i=0;i<4;i++){
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(!pass(yy,xx))continue;
        if(a[yy][xx] == from) dfs(yy,xx,from,to,a);
    }
}
bool isAnswer(int y, int x, vector<vector<int>> a){
    if(a[y][x] != b[y][x]) dfs(y,x,a[y][x], b[y][x], a);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    board.resize(n, vector<int>(m));
    b.resize(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>b[i][j];
        }
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(isAnswer(i,j, board)){
                cout<<"YES";
                return 0;
            }
        }
    }

    cout<<"NO";
    return 0;
}