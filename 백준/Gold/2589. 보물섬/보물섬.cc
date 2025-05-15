#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    int y,x;
    int dist;
};
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};
int n,m;
bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<m;
}

int answer = 0;
vector<vector<char>> graph;

void bfs(int y, int x){
    vector<vector<bool>> visited(n, vector<bool>(m));
    queue<Info> q;
    q.push({y,x, 0});
    visited[y][x] = true;

    while(!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        int dist = q.front().dist;
        q.pop();
        answer = max(answer, dist);

        for(int i=0;i<4;i++){
            int yy = y + dy[i];
            int xx = x + dx[i];
            if(!pass(yy,xx)) continue;

            if(!visited[yy][xx] && graph[yy][xx] == 'L'){
                q.push({yy,xx, dist+1});
                visited[yy][xx] = true;
            }
        }
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    graph.resize(n, vector<char>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>graph[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j] == 'L') bfs(i,j);
        }
    }
    cout<<answer;
    return 0;
}