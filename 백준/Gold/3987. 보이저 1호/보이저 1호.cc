#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 500000;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int n,m;
char board[505][505];
bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<m && board[y][x] != 'C';
}


int solve(int y, int x, int dir){
    // if()
    int cnt = 1;
    while(true){
        int yy = y + dy[dir];
        int xx = x + dx[dir];
        if(!pass(yy,xx)) break;
        y = yy;
        x = xx;

        if(board[y][x] == '/'){
            if(dir==0 || dir==1) dir = 1 - dir;
            if(dir==2 || dir==3) dir = 5 - dir;
        }
        else if(board[y][x] == '\\'){
            dir = 3 - dir;
        }

        cnt++;

        if(cnt >= INF) return INF;
    }

    return cnt;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }

    int y,x;cin>>y>>x;
    y--; x--;

    int max_dir = 0;
    int MAX = -1;
    for(int dir=0;dir<4;dir++){
        int cost = solve(y, x, dir);

        if(MAX < cost){
            max_dir = dir;
            MAX = cost;
        }
    }

    string answer = "URDL";

    cout<<answer[max_dir]<<'\n';
    if(MAX == INF) cout<<"Voyager";
    else cout<<MAX;

    return 0;
}