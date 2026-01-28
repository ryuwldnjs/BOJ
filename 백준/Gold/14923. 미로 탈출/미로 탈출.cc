#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    int y, x, magic;
    int cost;
};

int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

int hy,hx;
int ey,ex;
int n,m;
int board[1005][1005];

bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<m;
}


int bfs(){
    bool visited[1005][1005][2];//[y][x][magic] : y,x에서 magic번 마법을 썼을때의 상태공간
    queue<Info> q;
    q.push({hy, hx, 0, 0});
    visited[hy][hx][0] = true;

    while(!q.empty()){
        auto [y,x, magic, cost] = q.front(); q.pop();

        if(y == ey && x == ex) return cost;

        for(int i=0;i<4;i++){
            int yy = y + dy[i];
            int xx = x + dx[i];
            if(!pass(yy, xx)) continue;
            
            if(board[yy][xx] == 0 && !visited[yy][xx][magic]){
                visited[yy][xx][magic] = true;
                q.push({yy, xx, magic, cost + 1});
            }
            else if(board[yy][xx] == 1 && magic == 0 && !visited[yy][xx][magic+1]){
                visited[yy][xx][magic + 1] = true;
                q.push({yy, xx, magic + 1, cost + 1});
            }
        }
    }
    return -1;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    cin>>hy>>hx;
    cin>>ey>>ex;
    hy--;hx--;
    ey--;ex--;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }


    cout<<bfs();
    return 0;
}