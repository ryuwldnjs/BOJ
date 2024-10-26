#include <iostream>
#include <queue>
using namespace std;
struct Info{
    int x,y,dist;
};
int dx[8] = {-2,-1,1,2,2,1,-1,-2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};

int n,m;
int knightX,knightY;
int answer[550][550];
bool visited[550][550];

void bfs(){
    queue<Info> q;
    q.push({knightX,knightY, 0});

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int dist = q.front().dist;
        q.pop();
        answer[x][y] = dist;

        for(int i=0;i<8;i++){
            int xx = x + dx[i];
            int yy = y + dy[i];

        if([&](int x, int y) { return 0 < x && x <= n && 0 < y && y <= n; }(xx, yy) && !visited[xx][yy]){
            visited[xx][yy] = true;
            q.push({xx, yy, dist + 1});
        }
        }
    }
}
int main(){
    cin>>n>>m;
    cin>>knightX>>knightY;
    bfs();
    while(m--){
        int x,y; cin>>x>>y;
        cout<<answer[x][y]<<' ';
    }
    return 0;
}