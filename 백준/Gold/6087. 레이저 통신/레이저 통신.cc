#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 1e9;
struct Info{
    int y,x;
    int turn;
    int dir;
};
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

int w,h;
char m[105][105];
// int answer = INF;
//m[i][j]까지 왔을때의 최소 회전 수

// vector<vector<int>> visited(105, vector<int>(105, INF));
int visited[105][105][4];

bool pass(int y, int x){
    return 0<=y&&y<h && 0<=x&&x<w && m[y][x] != '*';
}


vector<Info> laser;
int bfs(){
    queue<Info> q;
    q.push(laser[0]);

    while(!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        int dir = q.front().dir;
        int turn = q.front().turn;
        q.pop();
        
        // printf("%d %d : %d\n",y,x,turn);
        for(int i=0;i<4;i++){
            int yy = y + dy[i];
            int xx = x + dx[i];
            int next_turn = turn;
            int next_dir = i;

            if(!pass(yy, xx)) continue;
            //갱신 가능할때만
            
            //방향 전환
            if(dir != next_dir){
                next_turn++;
            }
            if(visited[yy][xx][next_dir] > next_turn){
                q.push({yy, xx, next_turn, next_dir});
                visited[yy][xx][next_dir] = next_turn;
            }

        }
    }

    int answer = INF;
    for(int i=0;i<4;i++){
        answer = min(answer, visited[laser[1].y][laser[1].x][i]);
    }
    return answer;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>w>>h;

    fill(&visited[0][0][0], &visited[104][104][3], INF);

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>m[i][j];
            if(m[i][j] == 'C') laser.push_back({i,j,-1, -1});
        }
    }
    cout<<bfs();
    // cout<<answer;

    // cout<<visited[laser[1].y][laser[1].x][3];
    return 0;
}