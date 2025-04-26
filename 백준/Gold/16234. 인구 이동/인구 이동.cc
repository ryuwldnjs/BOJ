#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    int sum;
    int cnt;

    Info& operator+=(const Info& other){
        sum += other.sum;
        cnt += other.cnt;
        return *this;
    }
};
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};
int n,l,r;
vector<vector<int>> m, tmp, visited;
    
bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<n;
}

Info dfs(int y, int x){
    Info ret = {m[y][x], 1};
    visited[y][x] = 1;

    for(int i=0; i<4; i++){
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(!pass(yy, xx)) continue;

        int gap = abs(m[y][x] - m[yy][xx]);
        if(visited[yy][xx] == 0 && l<=gap&&gap<=r) ret += dfs(yy,xx);
    }
    return ret;
}
void setValue(int y, int x, int val){
    visited[y][x] = 2;
    tmp[y][x] = val;
    for(int i=0; i<4; i++){
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(!pass(yy, xx)) continue;
        if(visited[yy][xx] == 1) setValue(yy, xx, val);
    }
}

bool propagate(){
    tmp = vector<vector<int>>(n, vector<int>(n,-1));
    visited = vector<vector<int>>(n, vector<int>(n,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]){
                Info ret = dfs(i,j);
                int val = ret.sum / ret.cnt;
                setValue(i,j, val);
            }

        }
    }
    if(m == tmp) return false;
    m = tmp; //맵 갱신
    return true;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>l>>r;
    m.resize(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>m[i][j];
        }
    }

    int year=0;
    for(;;year++){
        if(!propagate()) break;
    }

    cout<<year;
    return 0;
}