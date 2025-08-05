#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 1e9;
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};
struct Info{
    int y,x;
    int cost;

    bool operator<(const Info& other)const{
        return cost > other.cost;
    }
};

int n,m,t,d;
vector<vector<int>> board;

bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<m;
}

vector<vector<int>> dijkstra(){
    vector<vector<bool>> visited(n, vector<bool>(m));
    priority_queue<Info> pq;
    vector<vector<int>> dist(n, vector<int>(m, INF));
    pq.push({0, 0, 0});
    dist[0][0] = 0;

    while(!pq.empty()){
        auto [y, x, cost] = pq.top();
        pq.pop();

        if(dist[y][x] < cost) continue;
        dist[y][x] = cost;


        for(int i=0;i<4;i++){
            int yy = y + dy[i];
            int xx = x + dx[i];
            if(!pass(yy, xx)) continue;
            if(abs(board[y][x] - board[yy][xx]) > t) continue;

            int next_cost = cost + 1;
            if(board[y][x] < board[yy][xx]) 
                next_cost = cost + (board[yy][xx] - board[y][x])*(board[yy][xx] - board[y][x]);

            if(dist[yy][xx] <= next_cost) continue;

            dist[yy][xx] = next_cost;
            pq.push({yy, xx, next_cost});
        }
    }
    return dist;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m>>t>>d;
    board.resize(n, vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;cin>>c;
            if('A' <= c && c <= 'Z') board[i][j] = c - 'A';
            else board[i][j] = c - 'a' + 26;
        }
    }

    vector<vector<int>> dist1, dist2;
    dist1 = dijkstra();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            board[i][j] *= -1;
        }
    }

    dist2 = dijkstra();

    //board 다 음수
    int answer = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dist1[i][j] + dist2[i][j] > d) continue;
            answer = max(answer, -board[i][j]);
        }
    }

    cout<<answer;
    return 0;
}