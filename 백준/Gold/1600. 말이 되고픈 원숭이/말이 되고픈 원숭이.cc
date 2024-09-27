#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct Info{
    int y, x, horse_step, dist;
};

int map[205][205];
bool visited[205][205][31];
int k, w,h;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int horse_dx[8] = {-2,-1,1,2,2,1,-1,-2};
int horse_dy[8] = {1,2,2,1,-1,-2,-2,-1};

bool pass(int y, int x){
    return 0<=y&&y<h && 0<=x&&x<w && map[y][x]==0;
}
int bfs(){
    queue<Info> q;

    q.push({0, 0, 0, 0});
    while(!q.empty()){
        Info now = q.front();
        q.pop();
        if(now.y == h-1 && now.x == w-1){ // 도착
            return now.dist;
        }

        for(int i=0;i<4;i++){ //원숭이 스텝
            int xx = now.x + dx[i];
            int yy = now.y + dy[i];
            int horse_step = now.horse_step;
            int dist = now.dist + 1;
            if(pass(yy,xx) && !visited[yy][xx][horse_step]){
                visited[yy][xx][horse_step] = true;
                q.push({yy, xx, horse_step, dist});
            }
        }

        if(now.horse_step >= k) continue;
        //말 스텝 기회가 아직 남아있을떄
        for(int i=0;i<8;i++){
            int xx = now.x + horse_dx[i];
            int yy = now.y + horse_dy[i];
            int horse_step = now.horse_step + 1;
            int dist = now.dist + 1;
            if(pass(yy, xx) && !visited[yy][xx][horse_step]){
                visited[yy][xx][horse_step] = true;
                q.push({yy, xx, horse_step, dist});
            }
        }
    }
    return -1;
}
int main(){
    cin>>k;
    cin>>w>>h;

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>map[i][j];
        }
    }

    cout<<bfs();
    return 0;
}