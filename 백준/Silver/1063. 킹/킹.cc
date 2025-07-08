#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    int x,y;
};
Info king,stone;

bool pass(int x, int y){
    return 0<=y&&y<8 && 0<=x&&x<8;
}

void move(int dx, int dy){
    int xx = king.x + dx;
    int yy = king.y + dy;
    if(!pass(xx,yy)) return;
    //체크판 침범

    if(xx==stone.x && yy==stone.y){
        int stonexx = stone.x + dx;
        int stoneyy = stone.y + dy;
        if(!pass(stonexx, stoneyy)) return;
        stone = {stonexx, stoneyy};
    }
    king = {xx,yy};
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    string k,s;
    int n;
    cin>>k>>s>>n;
    king = {k[0]-'A', k[1]-'1'};
    stone = {s[0]-'A', s[1]-'1'};
    
    while(n--){
        string com; cin>>com;
        if(com == "R") move(1,0);
        if(com == "L") move(-1,0);
        if(com == "B") move(0,-1);
        if(com == "T") move(0,1);
        if(com == "RT") move(1,1);
        if(com == "LT") move(-1,1);
        if(com == "RB") move(1,-1);
        if(com == "LB") move(-1,-1);
    }
    cout<<char('A'+king.x)<< char('1'+king.y)<<'\n';
    cout<<char('A'+stone.x) << char('1'+stone.y);
    return 0;
}