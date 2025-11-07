#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define SIZE (1<<7)
int tile[4][8][SIZE][SIZE];
//[dir][k][y][x]

//k번째의 dir(정방향,좌우반전,상하반전)방향 블럭을 (sy, sx)위치에 배치하기
//마지막 블럭 배치의 번호 리턴
void paste(int k, int dir, int sy, int sx, int num){
    if(dir == 0){
        for(int i=0;i<(1<<k);i++){
            for(int j=0;j<(1<<k);j++){
                if(tile[0][k][i][j] == -1) continue;
                tile[0][k+1][sy+i][sx+j] = tile[0][k][i][j] + num;
            }
        }
    }
    //좌우반전
    else if(dir == 1){
        for(int i=0;i<(1<<k);i++){
            for(int j=0;j<(1<<k);j++){
                if(tile[0][k][i][(1<<k)-j-1] == -1) continue;
                tile[0][k+1][sy+i][sx+j] = tile[0][k][i][(1<<k)-j-1] + num;
            }
        }
    }
    //상하반전
    else if(dir == 2){
        for(int i=0;i<(1<<k);i++){
            for(int j=0;j<(1<<k);j++){
                if(tile[0][k][(1<<k)-i-1][j] == -1) continue;
                tile[0][k+1][sy+i][sx+j] = tile[0][k][(1<<k)-i-1][j] + num;
            }
        }
    }
}

//이미 만들어진 정방향 블럭을 4방향으로 회전
void rotate(int k, int dir){
    int n = 1<<k;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //90도 회전변환
            tile[dir][k][i][j] = tile[dir-1][k][n-j-1][i];
        }
    }
}

void preprocess(){
    memset(tile, -1, sizeof(tile));
    tile[0][1][0][0] = tile[0][1][0][1] = tile[0][1][1][0] = 0;
    for(int j=1;j<4;j++) rotate(1, j);
    
    int num = 1;
    for(int i=1;i<7;i++){
        int block_num = 0;
        paste(i, 0, 0, 0, block_num); block_num += num;
        paste(i, 0, 1<<(i-1), 1<<(i-1), block_num); block_num += num;

        //좌우 반전
        paste(i, 1, 0, 1<<i, block_num); block_num += num;
        //상하 반전
        paste(i, 2, 1<<i, 0, block_num); block_num += num;
        
        num = block_num;
        //4방향 회전
        for(int j=1;j<4;j++) rotate(i+1, j);
    }
}

int answer[SIZE][SIZE];
int num=1;

void pasteToAnswer(int k, int dir, int sy, int sx){
    int n = 1<<k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(tile[dir][k][i][j] == -1) continue;
            answer[sy+i][sx+j] = tile[dir][k][i][j] + num;
        }
    }
    num += 1<<(2*k-2);
}
//23
//10
//[sy,sx] = 현재 사각형의 시작점
//[y,x] = k사각형에서의 배수구 상대적 위치
void solve(int k, int sy, int sx, int y, int x){
    if(k == 0) return;
    int n = 1<<(k-1);
    if(y>=n && x>=n){
        pasteToAnswer(k, 0, sy, sx);
        solve(k-1, sy + n, sx + n, y - n, x - n);
    }
    else if(y>=n && x<n){
        pasteToAnswer(k, 1, sy, sx);
        solve(k-1, sy + n, sx, y - n, x);
    }
    else if(y<n && x<n){
        pasteToAnswer(k, 2, sy, sx);
        solve(k-1, sy, sx, y, x);
    }
    else if(y<n && x>=n){
        pasteToAnswer(k, 3, sy, sx);
        solve(k-1, sy, sx + n, y, x - n);
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    preprocess();

    int k,x,y;
    cin>>k;
    cin>>x>>y;
    x--; y--;
    y = (1<<k) - y - 1;


    memset(answer, -1, sizeof(answer));
    solve(k, 0, 0, y, x);

    for(int i=0;i<(1<<k);i++){
        for(int j=0;j<(1<<k);j++){
            cout<<answer[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}