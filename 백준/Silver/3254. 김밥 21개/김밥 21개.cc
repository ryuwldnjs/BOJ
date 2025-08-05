#include <bits/stdc++.h>
#define FIRST 1
#define SECOND 2
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int game[22][50];



bool pass(int x, int y){
    return 0<=x&&x<22 && 0<=y&&y<50;
}

bool isWon(int x, int y, int player){
    if(game[x][y] != player) return false;

    for(int i=0;i<8;i++){
        bool isAnswer = true;
        for(int j=0;j<4;j++){
            int xx = x + j*dx[i];
            int yy = y + j*dy[i];
            if(!pass(xx, yy) || game[xx][yy] != player) isAnswer = false;
            
        }
        if(isAnswer) return true;

    }
    return false;
}

bool play(int col, int player){
    int row = 0;
    while(game[col][row] != 0) row++;
    
    game[col][row] = player;

    for(int i=0;i<22;i++){
        for(int j=0;j<50;j++){
            if(isWon(i,j, player)) return true;
        }
    }

    return false;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    for(int i=1;i<=21;i++){
        int a,b;cin>>a>>b;
        if(play(a, FIRST)){
            cout<<"sk "<<i;
            return 0;
        }
        if(play(b, SECOND)){
            cout<<"ji "<<i;
            return 0;
        }
        
    }
    cout<<"ss";
    return 0;
}