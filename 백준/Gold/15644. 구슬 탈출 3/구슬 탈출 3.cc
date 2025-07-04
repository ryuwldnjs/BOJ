#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Position{
    int y,x;

    bool operator==(const Position& other)const{
        return y==other.y && x==other.x;
    }

};
const Position GOALIN = {-1,-1};

struct Info{
    Position R;
    Position B;
    vector<int> command;
};
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
string COMMAND = "URDL";
Position R,B, goal;
int n,m;
vector<vector<char>> board;

void move(Position &me, Position &opposite, int dir){
    while(true){
        int yy = me.y + dy[dir];
        int xx = me.x + dx[dir];
        if(board[yy][xx] != '#' && (opposite.y != yy || opposite.x != xx)){
            me.y = yy;
            me.x = xx;
        }
        else break;
        if(me == goal){
            me = GOALIN;
            return;
        }
    }
}
void bfs(){
    queue<Info> q;
    q.push({R,B, {}});

    while(!q.empty()){
        Position R = q.front().R;
        Position B = q.front().B;
        vector<int> command = q.front().command;
        q.pop();
        if(command.size() > 10) break;
        if(R == GOALIN){
            cout<<command.size()<<'\n';
            for(int i:command){
                cout<<COMMAND[i];
            }
            return;
        }
        for(int i=0;i<4;i++){
            Position nextR = R;
            Position nextB = B;
            //먼저 움직여야할 공 선택
            if(i==0 && R.y < B.y
            || i==1 && R.x > B.x
            || i==2 && R.y > B.y
            || i==3 && R.x < B.x){
                move(nextR, nextB, i);
                move(nextB, nextR, i);
            }else{
                move(nextB, nextR, i); 
                move(nextR, nextB, i);
            }
            if(nextB == GOALIN) continue;
            vector<int> next_com = command;
            next_com.push_back(i);
            q.push({nextR, nextB, next_com});
        }

    }
    cout<<-1;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    board.resize(n, vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
            if(board[i][j] =='R'){
                R = {i,j};
                board[i][j] = '.';
            }
            if(board[i][j] =='B'){
                B = {i,j};
                board[i][j] = '.';
            }
            if(board[i][j] =='O'){
                goal = {i,j};
                board[i][j] = '.';
            }
        }
    }
    // move(R,B, 1);
    // move(B,R, 1);
    // printf("R:(%d,%d), B:(%d,%d)\n", R.y, R.x, B.y, B.x);
    bfs();
    return 0;
}