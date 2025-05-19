#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    int y,x;
    int dist;
};
struct Park{
    int idx;
    int dist;
};
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

char m[55][55];
int p_idx[55][55];//park_idx를 2차원배열에 저장
int park_idx;

vector<Info> car;
vector<vector<Park>> graph;

int row,col;
bool pass(int y, int x){
    return 0<=y&&y<row && 0<=x&&x<col && m[y][x] != 'X';
}

//car - park 전처리
void bfs(int car_idx){
    bool visited[55][55]={};
    queue<Info> q;
    q.push(car[car_idx]);

    while(!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        int dist = q.front().dist;
        q.pop();

        if(m[y][x] == 'P'){
            int park_idx = p_idx[y][x];
            graph[car_idx].push_back({park_idx, dist});
        }

        for(int i=0;i<4;i++){
            int yy = y + dy[i];
            int xx = x + dx[i];
            if(!pass(yy,xx)) continue;

            if(!visited[yy][xx]){
                q.push({yy, xx, dist+1});
                visited[yy][xx] = true;
            }
        }
    }
}

vector<int> l,r;
vector<bool> visited;
bool dfs(int x, int cost){
    if(visited[x]) return false;
    visited[x] = true;
    for(auto [y,dist]: graph[x]){
        if(dist > cost) continue;
        if(r[y] == -1 || dfs(r[y], cost)){
            r[y] = x;
            l[x] = y;
            return true;
        }
    }
    return false;
}
//모든 car들이 cost비용 이하로 주차가 가능한가
bool able(int cost){
    l = vector<int>(car.size(), -1);
    r = vector<int>(park_idx, -1);
    for(int i=0;i<car.size();i++){
        visited = vector<bool>(car.size());
        if(!dfs(i,cost)) return false; //주차 대란 발생
    }
    return true;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>row>>col;

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>m[i][j];
            if(m[i][j] == 'P') p_idx[i][j] = park_idx++;
            if(m[i][j] == 'C') car.push_back({i,j});
        }
    }

    graph.resize(car.size());
    for(int i=0;i<car.size();i++){
        bfs(i);
    }
    int lo=0;
    int hi=10000;
    for(int i=0;i<100;i++){
        int mid = (lo+hi)/2;
        if(able(mid)) hi = mid;
        else lo = mid;
    }
    if(able(hi)) cout<<hi;
    else if(able(lo)) cout<<lo;
    else cout<<-1;
    return 0;
}