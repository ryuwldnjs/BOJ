#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii=pair<int,int>;

const int INF = 1e5;
int n,m,t;

int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};
pii gram;
vector<vector<bool>> visited;
vector<vector<int>> graph, dist;

bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<m && graph[y][x] == 0;
}

void bfs(){
    queue<pii> q;

    q.push({0,0});
    dist[0][0] = 0;
    visited[0][0] = true;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int yy = y + dy[i];
            int xx = x + dx[i];
            
            if(pass(yy,xx) && !visited[yy][xx]){
                dist[yy][xx] = dist[y][x] + 1;
                q.push({yy,xx});
                visited[yy][xx] = true;
            }
        }
        
    }
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);

    cin>>n>>m>>t;
    visited = vector<vector<bool>>(n, vector<bool>(m));
    dist = vector<vector<int>>(n, vector<int>(m, INF));
    graph.resize(n, vector<int>(m));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>graph[i][j];
            if(graph[i][j] == 2){
                gram = {i,j};
                graph[i][j] = 0;
            }
        }
    }

    bfs();

    int answer = min(dist[n-1][m-1], dist[gram.first][gram.second] + n-1-gram.first + m-1-gram.second);
    if(answer <= t) cout<<answer;
    else cout<<"Fail";
    return 0;
}