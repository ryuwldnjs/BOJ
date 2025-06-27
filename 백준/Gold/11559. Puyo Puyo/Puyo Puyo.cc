#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

vector<vector<bool>> visited;
vector<vector<char>> field(12, vector<char>(6));

bool pass(int y, int x){
    return 0<=y&&y<12 && 0<=x&&x<6;
}
int dfs(int y, int x){//
    visited[y][x] = true;
    int ret = 1;
    for(int i=0;i<4;i++){
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(!pass(yy,xx)) continue;

        if(!visited[yy][xx] && field[y][x] == field[yy][xx]) ret += dfs(yy,xx);
    }
    return ret;
}
void remove(int y, int x, char target){
    field[y][x] = '.';

    for(int i=0;i<4;i++){
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(!pass(yy,xx)) continue;

        if(field[yy][xx] == target) remove(yy, xx, target);
    }
}
int pang(){
    visited = vector<vector<bool>>(12, vector<bool>(6));
    bool isPang = false;

    for(int i=0;i<12;i++){
        for(int j=0;j<6;j++){
            if(field[i][j] == '.') continue;
            if(!visited[i][j] && dfs(i,j) >= 4) {
                isPang = true;
                remove(i, j, field[i][j]);
            }            
        }
    }
    return isPang;
}


void move(){//중력 적용
    for(int j=0;j<6;j++){ // j열
        int pos = 11;
        for(int i=11;i>=0;i--){
            if(field[i][j] != '.') field[pos--][j] = field[i][j];
        }
        for(int i=pos;i>=0;i--) field[i][j] = '.';
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    for(int i=0;i<12;i++){
        for(int j=0;j<6;j++){
            cin>>field[i][j];
        }
    }


    int answer = 0;
    while(true){
        if(!pang()) break;
        move();
        answer++;
    }
    
    cout<<answer;
    return 0;
}