#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int dy[4] = {0,-1,0,1};
int dx[4] = {-1,0,1,0};

int n,m;
vector<vector<int>> wall, number;
vector<vector<bool>> visited;
vector<int> room;

bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<m;
}
int dfs(int y, int x){
    visited[y][x] = true;
    number[y][x] = room.size();
    int ret = 1;
    for(int i=0;i<4;i++){
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(!pass(yy, xx) || visited[yy][xx]) continue;
        if(wall[y][x] & (1<<i) || wall[yy][xx] & (1<<((i+2)%4))) continue;
        ret += dfs(yy, xx);
    }
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>m>>n;
    wall.resize(n, vector<int>(m));
    number.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>wall[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]) room.push_back(dfs(i,j));
        }
    }
    // sort(room.begin(), room.end());

    int MAX = 0;
    for(int y=0;y<n;y++){
        for(int x=0;x<m;x++){
            for(int i=0;i<4;i++){
                int yy = y + dy[i];
                int xx = x + dx[i];
                if(!pass(yy,xx)) continue;
                int a = number[y][x];
                int b = number[yy][xx];
                if(a != b) MAX = max(MAX, room[a] + room[b]);
            }
        }
    }

    sort(room.begin(), room.end());
    cout<<room.size()<<'\n';
    cout<<room.back()<<'\n';
    cout<<MAX<<'\n';
    return 0;
}