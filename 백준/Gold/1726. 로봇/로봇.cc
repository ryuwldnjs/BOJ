#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;
struct Info{
    int y, x, dir;
};

int m,n;
int s_y,s_x,s_d;
int e_y,e_x,e_d;
vector<vector<int>> map;

        //0 : x++
        //1 : x--
        //2 : y++
        //3 : y--
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int l_dir[4] = {2, 3, 1, 0};
int r_dir[4] = {3, 2, 0, 1};
bool pass(int y, int x){
    return 0<=y&&y<m && 0<=x&&x<n && map[y][x]==0;
}

void bfs(){
    queue<Info> q;
    vector<vector<vector<int>>> dist(m, vector<vector<int>>(n, vector<int>(4, INF)));
    //dist[y][x][dir]상태공간의 거리
    q.push({s_y, s_x, s_d});
    dist[s_y][s_x][s_d] = 0;

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int dir = q.front().dir;
        q.pop();
        // printf("%d %d %d: %d\n", y,x,dir, dist[y][x][dir]);
        if(x==e_x && y==e_y && dir==e_d){
            cout<<dist[y][x][dir];
            return;
        }
        //회전 두가지
        // int l_dir, r_dir; //왼쪽, 오른쪽 회전시 방향

        if(dist[y][x][dir]+1 < dist[y][x][l_dir[dir]]){
            dist[y][x][l_dir[dir]] = dist[y][x][dir]+1;
            q.push({y,x,l_dir[dir]});
        }

        if(dist[y][x][dir]+1 < dist[y][x][r_dir[dir]]){
            dist[y][x][r_dir[dir]] = dist[y][x][dir]+1;
            q.push({y,x,r_dir[dir]});
        }

        for(int i=1;i<=3;i++){ //1,2,3거리 이동
            int yy = y + i * dy[dir];
            int xx = x + i * dx[dir];

            if(!pass(yy,xx)) break;
            if(dist[y][x][dir]+1 < dist[yy][xx][dir]){
                dist[yy][xx][dir] = dist[y][x][dir] + 1;
                q.push({yy,xx,dir});
            }
        }
    }
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>m>>n;
    map.resize(m, vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    cin>>s_y>>s_x>>s_d;
    cin>>e_y>>e_x>>e_d;
    // if
    s_y--; s_x--; s_d--;
    e_y--; e_x--; e_d--;
    bfs();
    return 0;
}