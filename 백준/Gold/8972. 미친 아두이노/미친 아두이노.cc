#include <bits/stdc++.h>
#define BOMB 'X'
using namespace std;

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int dy[10] = {0,1,1,1,0,0,0,-1,-1,-1};
int dx[10] = {0,-1,0,1,-1,0,1,-1,0,1};
int r,c;
vector<vector<char>> board;
pii me; //종수 위치

//종수 움직이기
bool move(int dir){
    me.first += dy[dir];
    me.second += dx[dir];
    if(board[me.first][me.second] == 'R') return false;


    vector<vector<char>> tmp(r, vector<char>(c, '.'));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(board[i][j] == '.') continue;

            auto [yy, xx] = make_pair(i,j);

            if(me.first < i) yy--;
            else if(me.first > i) yy++;
            if(me.second < j) xx--;
            else if(me.second > j) xx++;

            if(me.first == yy && me.second == xx) return false;


            if(tmp[yy][xx] == 'R' || tmp[yy][xx] == BOMB) tmp[yy][xx] = BOMB;
            else tmp[yy][xx] = 'R';
        }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(tmp[i][j] == BOMB) tmp[i][j] = '.';
        }
    }

    board = tmp;
    return true;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>r>>c;
    board.resize(r, vector<char>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>board[i][j];
            if(board[i][j] == 'I'){
                me = {i,j};
                board[i][j] = '.';
            }
        }
    }
    
    char x;
    for(int i=1; cin>>x ;i++){
        int dir = x - '0';
        if(!move(dir)){
            cout<<"kraj "<<i;
            return 0;
        }

    }

    board[me.first][me.second] = 'I';
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<board[i][j];
        }
        cout<<'\n';
    }
    return 0;
}