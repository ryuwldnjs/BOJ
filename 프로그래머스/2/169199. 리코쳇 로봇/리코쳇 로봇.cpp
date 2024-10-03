#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
using pii=pair<int,int>;
struct Info{
    int y, x, dist;
};

int h, w;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
bool pass(vector<string> &board, int y, int x){
    return 0<=y&&y<h && 0<=x&&x<w && board[y][x] =='.';
}
pii findNextPos(vector<string> &board, int y, int x, int dir){

    while(pass(board, y+dy[dir], x+dx[dir])){
        x += dx[dir];
        y += dy[dir];
    }
    return {y,x};
}
int bfs(vector<string> &board, int start_y, int start_x, int end_y, int end_x){
    queue<Info> q;
    vector<vector<bool>> visited(h, vector<bool>(w));
    
    q.push({start_y, start_x, 0});
    visited[start_y][start_x] = true;
    
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int dist = q.front().dist;
        q.pop();
        
        for(int i=0;i<4;i++){
            pii next = findNextPos(board, y,x,i);
            int yy = next.first;
            int xx = next.second;
            
            if(pass(board,yy,xx) && !visited[yy][xx]){
                q.push({yy, xx, dist+1});
                visited[yy][xx] = true;
            }
        }
        
        if(x == end_x && y == end_y){
            return dist;
        }
    }
    
    return -1;
}
int solution(vector<string> board) {
    int start_y,start_x; // 시작점
    int end_y, end_x;
    h = board.size();
    w = board[0].size();
    
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(board[i][j] == 'R'){
                start_y = i; start_x = j;
                board[i][j] = '.';
            }
            if(board[i][j] == 'G'){
                end_y = i; end_x = j;
                board[i][j] = '.';
            }
        }
    }
    
    int answer = bfs(board, start_y, start_x, end_y, end_x);
    return answer;
}