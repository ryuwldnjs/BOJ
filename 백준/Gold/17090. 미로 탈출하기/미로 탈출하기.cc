#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
unordered_map<char, int> dir;

int n,m;
char board[505][505];
bool visited[505][505];
bool isAnswer[505][505];

bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<m;
}
bool solve(int y, int x){
    visited[y][x] = true;
    
    int yy = y + dy[dir[board[y][x]]];
    int xx = x + dx[dir[board[y][x]]];
    if(!pass(yy,xx)) return isAnswer[y][x] = true;


    if(!visited[yy][xx]) isAnswer[y][x] = solve(yy,xx);
    else isAnswer[y][x] = isAnswer[yy][xx];
    return isAnswer[y][x];
}


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    dir['U']=0;
    dir['R']=1;
    dir['D']=2;
    dir['L']=3;

    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }

    int answer = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]) solve(i,j);
            if(isAnswer[i][j]) answer++;
        }
    }

    cout<<answer;
    return 0;
}