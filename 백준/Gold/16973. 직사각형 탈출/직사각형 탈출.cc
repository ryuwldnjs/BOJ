#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    int y,x;
    int cost;
};
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};
int arr[1005][1005], board[1005][1005];
int h,w, sr, sc, fr, fc;
int n,m;

int getPsum(int y1, int x1, int y2, int x2){
    y2 = min(y2, n);
    x2 = min(x2, m);

    return arr[y2][x2] - arr[y1-1][x2] - arr[y2][x1-1] + arr[y1-1][x1-1];
}

bool pass(int y, int x){
    return 1<=y&&y<=n-h+1 && 1<=x&&x<=m-w+1 && board[y][x] != 1;
}

void bfs(){
    queue<Info> q;
    bool visited[1005][1005]={};
    q.push({sr, sc, 0});
    while(!q.empty()){
        auto [y, x, cost] = q.front();
        q.pop();

        if(y == fr && x == fc){
            cout<<cost;
            return;
        }

        for(int i=0;i<4;i++){
            int yy = y + dy[i];
            int xx = x + dx[i];
            if(!pass(yy,xx) || visited[yy][xx]) continue;
            visited[yy][xx] = true;
            q.push({yy, xx, cost + 1});
        }
    }

    cout<<-1;
    return;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
            arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    }
    cin>>h>>w>>sr>>sc>>fr>>fc;


    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int ones = getPsum(i, j, i+h-1, j+w-1);

            if(ones) board[i][j] = 1;
        }
    }


    bfs();

    return 0;
}