#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
vector<vector<int>> a;
vector<pii> cctv;
int n,m;

bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<m && a[y][x]!=6;
}

void go(vector<vector<int>> &graph, int y, int x,int dir){
    for(int i=0;i<10;i++){
        int yy = y + i*dy[dir];
        int xx = x + i*dx[dir];
        if(!pass(yy,xx)) return;
        graph[yy][xx] = -1;
    }
}
int solve(vector<vector<int>>&graph, int idx){
    if(idx == cctv.size()){
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(graph[i][j] == 0) cnt++;
            }
        }
        return cnt;
    }
    int y = cctv[idx].first;
    int x = cctv[idx].second;
    int type = a[y][x];

    int ret = 1e9;
    for(int i=0;i<4;i++){
        vector<vector<int>>tmp = graph;
        go(tmp, y,x,i);
        if(type==3 || type==4 || type==5) go(tmp, y,x, (i+1)%4);
        if(type==2 || type==4 || type==5) go(tmp,y,x,(i+2)%4);
        if(type==5) go(tmp,y,x,(i+3)%4);
        ret = min(ret, solve(tmp, idx+1));
    }
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    a.resize(n, vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(1<=a[i][j] && a[i][j]<=5){
                cctv.push_back({i,j});
                // a[i][j] = -1;
            }
        }
    }

    cout<<solve(a, 0);
    return 0;
}