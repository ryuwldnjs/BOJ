#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int dy[4] = {0,1,0,-1};
int dx[4] = {-1,0,1,0};

int n;
int ratios[4][5][5] = {{{0,0,2,0,0}, {0,10,7,1,0}, {5,0,0,0,0}, {0,10,7,1,0}, {0,0,2,0,0}}, };
int board[505][505];

//4방향 비율 캐싱
void preprocess(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            int y=i, x=j;        
            for(int dir=1;dir<4;dir++){
                int yy = 4-x, xx=y;
                ratios[dir][yy][xx] = ratios[0][i][j];
                y=yy, x=xx;
            }
        }
    }
}

bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<n;
}

int scatter(int y, int x, int dir){
    int ret = 0; //격자 밖으로 나간 모래의 양
    int sand = board[y][x];

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            int amount = sand * ratios[dir][i][j] / 100;
            board[y][x] -= amount;
            int yy = y + i - 2;
            int xx = x + j - 2;
            if(!pass(yy, xx)){
                ret += amount;
                continue;
            }

            board[yy][xx] += amount;
        }
    }

    int yy = y+dy[dir], xx = x+dx[dir];
    if(pass(yy,xx)) board[yy][xx] += board[y][x]; //잔여물 전부 이동
    else ret += board[y][x];
    board[y][x] = 0; //잔여물 제거

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         printf("%2d ", board[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    
    return ret;
}

int solve(){
    int answer = 0;
    int dir=0;
    int y = n/2, x = n/2;
    for(int i=2;;i++){
        for(int j=0;j<i/2;j++){
            int yy = y + dy[dir];
            int xx = x + dx[dir];

            answer += scatter(yy, xx, dir);
            y = yy, x = xx;

            if(y==0&&x==0) return answer;
        }
        dir = (dir+1) % 4;
    }
    return -1;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    preprocess();

    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }

    cout<<solve();
    return 0;
}