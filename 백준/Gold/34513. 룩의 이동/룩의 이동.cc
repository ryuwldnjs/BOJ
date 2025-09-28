#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    int y,x;
    int cost;
};
const int INF = 1e9;

int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

int sy,sx;
int n;
char board[1005][1005];

bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<n && board[y][x] != 'B';
}

void bfs(){
    queue<Info> q;
    int dist[1005][1005];
    fill(&dist[0][0], &dist[1004][1004], INF);

    q.push({sy,sx,0});
    dist[sy][sx] = 0;

    while(!q.empty()){
        auto [y,x,cost] = q.front();
        q.pop();

        if(cost > dist[y][x]) continue;

        if(board[y][x] == 'K'){
            cout<<cost;
            return;
        }

        for(int i=0;i<4;i++){
            int yy = y;
            int xx = x;
            while(true){
                yy += dy[i];
                xx += dx[i];
                if(!pass(yy,xx)) break;
                if(cost >= dist[yy][xx]) break;

                if(cost+1 < dist[yy][xx]){
                    q.push({yy,xx,cost+1});
                    dist[yy][xx] = cost+1;
                }

                if(board[yy][xx] == 'W' || board[yy][xx] == 'K') break;
            }
            // printf("\n");
        }
    }

    cout<<-1;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
            if(board[i][j] == 'R'){
                sy = i;
                sx = j;
                board[i][j] = '.';
            }
        }
    }

    bfs();
    return 0;
}