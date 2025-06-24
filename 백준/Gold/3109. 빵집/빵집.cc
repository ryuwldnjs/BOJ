#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
vector<vector<char>> a;
vector<vector<bool>> visited;
int r,c;

bool pass(int y, int x){
    return 0<=y&&y<r && 0<=x&&x<c && a[y][x] == '.';
}
bool dfs(int y, int x){
    visited[y][x] = true;
    if(x == c-1) return true;


    for(int dy=-1;dy<=1;dy++){
        int yy = y + dy;
        int xx = x + 1;
        if(!pass(yy,xx)) continue;
        if(!visited[yy][xx] && dfs(yy, xx)) return true;
    }
    return false;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>r>>c;
    a.resize(r, vector<char>(c));
    visited.resize(r, vector<bool>(c));

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>a[i][j];
        }
    }


    int answer = 0;
    for(int i=0;i<r;i++){
        answer += dfs(i,0);
    }
    cout<<answer;
    return 0;
}