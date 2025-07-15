#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
vector<vector<char>> board;
vector<int> directions;
int n,m;

bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<m;
}

bool canExit(int y, int x){
    for(int dir: directions){
        int yy = y + dy[dir];
        int xx = x + dx[dir];
        while(pass(yy, xx) && board[yy][xx] != '#'){
            y = yy;
            x = xx;
            yy = y + dy[dir];
            xx = x + dx[dir];
        }
        if(board[y][x] =='O') return true;
    }
    return false;
}

bool canAllExit(){
    bool isAnswer = true;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] != '.') continue;
            if(!canExit(i,j)) isAnswer = false;
        }
    }
    return isAnswer;
}

vector<int> answer;
void dfs(int idx, int dir){
    if(answer.size()) return;

    if(idx == 10){
        // for(int i: directions) printf("%d",i);
        // printf("\n");
        if(canAllExit()) answer = directions;
        return;
    }
    for(int i=0;i<4;i++){
        if(dir == i || dir>=0 && abs(dir-i)==2) continue;
        directions.push_back(i);
        dfs(idx + 1, i);
        directions.pop_back();
    }
}
void solve(){
    cin>>n>>m;
    board = vector<vector<char>>(n, vector<char>(m));
    directions.clear();
    answer.clear();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }

    dfs(0,-1);

    string x = "URDL";
    if(answer.empty()) cout<<"XHAE\n";
    else{
        for(int i:answer) cout<<x[i];
        cout<<'\n';
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}