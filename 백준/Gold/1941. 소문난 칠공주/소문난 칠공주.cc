#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int m[5][5];
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};
vector<vector<bool>> isChecked(5, vector<bool>(5));

pii operator+=(pii &a, const pii &b){
    a.first += b.first;
    a.second += b.second;
    return a;
}
bool pass(int y, int x){
    return 0<=y&&y<5 && 0<=x&&x<5;
}
pii dfs(int y, int x, vector<vector<bool>> &visited){
    visited[y][x] = true;
    pii ret = {1, m[y][x]}; //total, 다솜

    for(int i=0;i<4;i++){
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(!pass(yy,xx) || !isChecked[yy][xx] || visited[yy][xx]) continue;
        ret += dfs(yy, xx, visited); 
    }
    return ret;
}
bool isValidated(int y, int x){
    vector<vector<bool>> visited(5, vector<bool>(5));
    pair<int,int> tmp = dfs(y, x, visited);
    int total_cnt = tmp.first;
    int S_cnt = tmp.second;
    if(total_cnt == 7 && S_cnt >= 4) return true;
    return false;
}

int solve(int idx, int depth){
    int ret = 0;
    if(depth == 7){
        if(isValidated(idx/5, idx%5)) return 1;
        return 0;
    }

    for(int next = idx+1; next < 25; next++){
        int y = next / 5;
        int x = next % 5;
        isChecked[y][x] = true;
        ret += solve(next, depth + 1);
        isChecked[y][x] = false;
    }
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            char x; cin>>x;
            if(x == 'S') m[i][j] = 1;
        }
    }
    int answer = 0;
    for(int i=0;i<19;i++){
        int y = i/5;
        int x = i%5;
        isChecked[y][x] = true;
        answer += solve(i, 1);
        isChecked[y][x] = false;
    }
    cout<<answer;
    return 0;
}