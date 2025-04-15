#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Info{
    int y, x;
};
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};
int n;
queue<Info> q;
// vector<Info> city; //city[i]: i번 도시가 있는 어느 한 좌표
vector<vector<int>> map;
int city_idx;

bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<n;
}

vector<vector<bool>> visited;
//도시별 번호 매기기
void numbering(int idx, int y, int x){
    map[y][x] = idx;
    visited[y][x] = true;
    for(int i=0;i<4;i++){
        int yy = y + dy[i];
        int xx = x + dx[i];
        
        if(!pass(yy,xx)) continue;
        if(!visited[yy][xx] && map[yy][xx] == 1) numbering(idx, yy,xx);
    }
}
void dfs(int y, int x, vector<vector<bool>> &visited){
    visited[y][x] = true;

    for(int i=0;i<4;i++){
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(pass(yy,xx) && !visited[yy][xx] && map[yy][xx] != 0){
            dfs(yy,xx, visited);
        }
    }
}
int getCityCnt(){
    int component =0;
    vector<vector<bool>> visited(n, vector<bool>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j] && map[i][j] != 0){
                dfs(i,j, visited);
                component++;
            }
        }
    }
    return component;
}

void bfs(){
    vector<vector<int>> tmp = map;
    int answer =0;
    //loop 1회당 다리 길이 2씩 늘어남
    while(!q.empty()){
        int sz = q.size();

        while(sz--){
            int y = q.front().y;
            int x = q.front().x;
            q.pop();
    
            for(int i=0;i<4;i++){
                int yy = y + dy[i];
                int xx = x + dx[i];

                if(!pass(yy,xx)) continue;
                if(map[yy][xx] == 0){
                    if(tmp[yy][xx] == 0){
                        q.push({yy,xx});
                        tmp[yy][xx] = map[y][x];
                    }
                    else if(tmp[yy][xx] != map[y][x]){ //다른 도시에서 먼저 방문했을때
                        // cout<<y<<' '<<x<<'\n';
                        // cout<<tmp[yy][xx]<<' '<<map[y][x]<<'\n';
                        cout<<answer+1<<'\n';
                        return;
                    }
                }
            }
        
        }
        //원본 반영
        map = tmp;
        
        answer+=2;
        //두 도시가 인접한 경우가 발생
        if(getCityCnt() < city_idx){
            cout<<answer;
            return;
        }
    }

}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    visited.resize(n, vector<bool>(n));
    map.resize(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j] && map[i][j]==1) numbering(++city_idx, i, j);
        }
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int dir=0;dir<4;dir++){
                int yy = i + dy[dir];
                int xx = j + dx[dir];
                if(map[i][j] != 0 && pass(yy,xx) && map[yy][xx] == 0){
                    q.push({i,j});
                    break;
                }
            }
        }
    }

    bfs();
    return 0;
}