#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int dy[8] = {-1,-1,0,1,1,1,0,-1};
int dx[8] = {0,1,1,1,0,-1,-1,-1};

int n,m;
int board[105][75];
bool visited[105][75];
bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<m;
}

bool dfs(int y, int x){
    visited[y][x] = true;
    bool isAnswer = true;

    for(int i=0;i<8;i++){
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(!pass(yy, xx)) continue;
        if(board[yy][xx] > board[y][x]) isAnswer = false;

        if(board[yy][xx] == board[y][x] && !visited[yy][xx])
            isAnswer = dfs(yy,xx) && isAnswer;
    }
    return isAnswer;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }

    int answer = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j]) continue;
            if(dfs(i,j)) answer++;
                
        }
    }

    cout<<answer;
    return 0;
}