#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define OVER 0
#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4
#define UNDER 5
int dh[6] = {-1,0,0,0,0,1};
int dy[6] = {0,-1,0,1,0,0};
int dx[6] = {0,0,1,0,-1,0};

int r,c;
char board[205][205];
bool visited[2][205*2][205*2];//각 정육면체를 8등분

//outOfBound방지
bool pass(int h, int y, int x){
    return 0<=h&&h<2 && 0<=y&&y<r*2 && 0<=x&&x<c*2;
}

//8등분했을때 실제로 연결되어 있는지
bool connected(int h1, int y1, int x1, int h2, int y2, int x2){
    //다른 정육면체
    if(h1/2 != h2/2 || y1/2 != y2/2 || x1/2 != x2/2) return true;

    //같은 정육면체
    char shape = board[y1/2][x1/2];
    if(shape == 'H' && x1 != x2) return true;
    if(shape == 'I' && y1 != y2) return true;
    if(shape == 'O' && h1 != h2) return true;
    return false;
}

void dfs(int h, int y, int x){
    visited[h][y][x] = true;

    for(int i=0;i<6;i++){
        int hh = h + dh[i];
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(!pass(hh,yy,xx)) continue;

        if(!visited[hh][yy][xx] && connected(h,y,x, hh,yy,xx)) 
            dfs(hh,yy,xx);
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>board[i][j];
        }
    }

    int answer = 0;
    for(int i=0;i<2;i++){
        for(int j=0;j<r*2;j++){
            for(int k=0;k<c*2;k++){
                if(!visited[i][j][k]){ 
                    dfs(i,j,k);
                    answer++;
                }
            }
        }
    }
    cout<<answer;
    return 0;
}