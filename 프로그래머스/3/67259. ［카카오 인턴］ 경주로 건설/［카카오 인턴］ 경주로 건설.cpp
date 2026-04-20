#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
struct Info{
    int y,x, dir, cost;
    bool operator<(const Info other)const{
        return cost > other.cost;
    }
};

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int n;
vector<vector<int>>board;

bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<n && board[y][x] == 0;
}

int dijkstra(){
    priority_queue<Info> pq;
    int dist[30][30][2];
    fill(&dist[0][0][0], &dist[29][29][2], INF);
    dist[0][0][0] = dist[0][0][1] = 0;
    pq.push({0,0,0,0});
    pq.push({0,0,1,0});
    
    while(!pq.empty()){
        auto [y,x,dir,cost] = pq.top();
        pq.pop();
        if(cost > dist[y][x][dir]) continue;
        // printf("%d %d %d : %d\n", y,x,dir,cost);
        for(int i=0;i<4;i++){
            int yy = y + dy[i];
            int xx = x + dx[i];
            if(!pass(yy,xx)) continue;
            
            int next_cost = cost + 100;
            if(dir != i%2) next_cost += 500;
            
            if(next_cost >= dist[yy][xx][i%2]) continue;
            pq.push({yy,xx,i%2, next_cost});
            dist[yy][xx][i%2] = next_cost;
        }
        
    }
    
    return min(dist[n-1][n-1][0], dist[n-1][n-1][1]);
}

int solution(vector<vector<int>> _board) {
    board = _board;
    n = board.size();
    
    int answer = dijkstra();    
    return answer;
}