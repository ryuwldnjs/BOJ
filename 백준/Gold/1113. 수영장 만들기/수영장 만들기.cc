#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> map, flood_map;
vector<vector<bool>> visited;
int n,m;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
bool pass(int y, int x){
    return 0<=y && y<=n+1 && 0<=x && x<=m+1;
}
void flood(int y, int x, int level){
    flood_map[y][x] = level;
    visited[y][x] = true;
    for(int i=0;i<4;i++){
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(pass(yy, xx) && !visited[yy][xx] && map[yy][xx] <= level) flood(yy,xx,level);
    }
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    map = flood_map = vector<vector<int>>(n+2, vector<int>(m+2));
    visited.resize(n+2, vector<bool>(m+2));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char x; cin>>x;
            map[i][j] = x - '0';
        }
    }

    for(int i=9;i>=1;i--){
        visited = vector<vector<bool>>(n+2, vector<bool>(m+2));
        flood(0,0,i);
    }

    int answer = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            answer += flood_map[i][j] - map[i][j];
        }
    }
    cout<<answer;
    return 0;
}