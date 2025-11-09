#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 1e8;
struct Info{
    int y,x;
    int cost;
    bool operator<(const Info &other)const{
        return cost > other.cost;
    }
};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int h,w;
char board[105][105];

int distSum[105][105];

bool pass(int y, int x){
    return 0<=y&&y<=h+1 && 0<=x&&x<=w+1 && board[y][x] != '*';
}

//(a,b)를 시작으로 모든 점에 대한 비용 계산
void dijkstra(pii start){
    int dist[105][105];
    fill(&dist[0][0], &dist[104][104], INF);
    dist[start.first][start.second] = 0;

    priority_queue<Info> pq;
    pq.push({start.first, start.second, 0});

    while(!pq.empty()){
        auto [y,x,cost] = pq.top();
        pq.pop();
        if(cost > dist[y][x]) continue;

        for(int i=0;i<4;i++){
            int yy = y + dy[i];
            int xx = x + dx[i];
            if(!pass(yy,xx)) continue;
            int next_cost = cost + (board[yy][xx]=='#');

            if(next_cost >= dist[yy][xx]) continue;

            dist[yy][xx] = next_cost;
            pq.push({yy, xx, next_cost});
        }
    }

    for(int i=0;i<=h+1;i++){
        for(int j=0;j<=w+1;j++){
            distSum[i][j] += dist[i][j];
        }
    }
}

// 죄수1, 죄수2, 외부의 상근이가 각각 출발해서 최소 비용으로 한 점에서 만나는 곳 찾기
// 문에서 만나는경우는 3명이 중복 집계가 되기때문에 -2 처리

void solve(){
    memset(board, 0, sizeof(board));
    memset(distSum, 0, sizeof(distSum));
    cin>>h>>w;
    
    vector<pii> prisoner;

    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>board[i][j];
            if(board[i][j] == '$'){
                prisoner.push_back({i,j});
                board[i][j] = '.';
            }
        }
    }

    dijkstra(prisoner[0]);
    dijkstra(prisoner[1]);
    dijkstra({0,0});

    int answer = INF;
    for(int i=0;i<=h+1;i++){
        for(int j=0;j<=w+1;j++){
            int val = distSum[i][j];
            if(board[i][j] == '#') val -= 2;

            answer = min(answer, val);
        }
    }

    cout<<answer<<'\n';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}