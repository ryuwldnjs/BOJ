#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 1e9;
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};
int n;
int m[55][55];
bool visited[55][55][3000];

int answer = INF;

bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<n;
}

void dfs(int y, int x, int change){
    if(change > 500) return;
    visited[y][x][change] = true;
    if(answer < change) return;

    // printf("%d %d %d\n", y,x,change);
    if(y==n-1 && x==n-1){
        answer = min(answer, change);
        return;
    }
    for(int i=0;i<4;i++){
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(!pass(yy,xx)) continue;
        
        int next_change = change + (m[yy][xx] == 0);
        if(!visited[yy][xx][next_change]) dfs(yy, xx, next_change);
    }
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char x; cin>>x;
            m[i][j] = x - '0';
        }
    }
    
    dfs(0,0,0);
    cout<<answer;
    return 0;
}