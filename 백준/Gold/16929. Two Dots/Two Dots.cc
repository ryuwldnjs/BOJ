#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

int n,m;
char graph[55][55];
int visited[55][55];

bool isAnswer;
//이전 [y,x] = [py,px]
bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<m;
}
void dfs(int y, int x, int py, int px){
    if(visited[y][x]){
        isAnswer = true;
        return;
    }
    visited[y][x] = 1;

    for(int i=0;i<4;i++){
        int yy = y + dy[i];
        int xx = x + dx[i];
        //다른 알파벳
        if(!pass(yy,xx) || graph[yy][xx] != graph[y][x]) continue;
        //직전에 왔던 경로
        if(yy==py && xx==px) continue;
        dfs(yy, xx, y, x);

    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0; j<m; j++){
            cin>>graph[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]) dfs(i,j, -1, -1);
        }
    }

    cout<<(isAnswer ? "Yes" : "No");
    return 0;
}