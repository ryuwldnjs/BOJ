#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 1e9;
struct Info{
    int h,y,x;
    int dist;

    bool operator==(const Info &other)const{
        return h==other.h && y==other.y && x==other.x;
    }
};

int dh[6] = {-1,0,0,0,0,1};
int dy[6] = {0,-1,0,1,0,0};
int dx[6] = {0,0,-1,0,1,0};
vector<vector<vector<int>>>level[5];//각 층별 존재하는 경우 4가지 담기 

bool pass(int h, int y, int x){
    return 0<=h&&h<5 && 0<=y&&y<5 && 0<=x&&x<5; 
}
int bfs(vector<vector<vector<int>>> &maze, Info s, Info d){
    if(!maze[s.h][s.y][s.x] || !maze[d.h][d.y][d.x]) return INF;

    queue<Info> q;
    vector<vector<vector<bool>>> visited(5, vector<vector<bool>>(5, vector<bool>(5)));
    q.push(s);
    visited[s.h][s.y][s.x] = true;

    while(!q.empty()){
        int h = q.front().h;
        int y = q.front().y;
        int x = q.front().x;
        int dist = q.front().dist;
        q.pop();
        
        if(h==d.h && y==d.y && x==d.x) return dist;

        for(int i=0;i<6;i++){
            int hh = h + dh[i];
            int yy = y + dy[i];
            int xx = x + dx[i];

            if(!pass(hh,yy,xx)) continue;

            if(maze[hh][yy][xx] && !visited[hh][yy][xx]){
                q.push({hh,yy,xx,dist+1});
                visited[hh][yy][xx] = true;
            }
        }

    }

    return INF;
}
int solve(vector<int> &selected, int now){
    int ret = INF;
    if(now == 5){
        vector<int> idx ={0,1,2,3,4};
        //층간의 셔플링
        do{
            vector<vector<vector<int>>> maze;
            int index=0;
            for(int i:idx) maze.push_back(level[i][selected[i]]);

            ret = min(ret, bfs(maze, {0,0,0,0}, {4,4,4,0}));
        }while(next_permutation(idx.begin(), idx.end()));

        return ret;
    }

    for(int i=0;i<4;i++){
        selected[now] = i;
        ret = min(ret, solve(selected, now+1));
    }
    
    return ret;
}


void rotate(vector<vector<int>> &origin){
    vector<vector<int>> tmp = origin;

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            int y = j;
            int x = 4 - i;
            tmp[y][x] = origin[i][j];
        }
    }
    origin = tmp;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    vector<vector<vector<int>>> maze(5,vector<vector<int>>(5, vector<int>(5)));
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                cin>>maze[i][j][k];
            }
        }
    }
    for(int i=0;i<5;i++){
        vector<vector<int>> target = maze[i];
        for(int j=0;j<4;j++){
            rotate(target);
            level[i].push_back(target);
        }
    }
    

    vector<int> selected(5);
    int answer = solve(selected, 0);
    if(answer == INF) cout<<-1;
    else cout<<answer;
    return 0;
}