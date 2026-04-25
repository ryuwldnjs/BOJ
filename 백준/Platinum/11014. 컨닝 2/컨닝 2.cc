#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
vector<vector<int>> graph;
int dy[6] = {-1,-1,0,0,1,1};
int dx[6] = {-1,1,-1,1,-1,1};

int n,m;
char arr[85][85];
vector<bool> visited;
vector<int> l,r;
bool dfs(int x){
    if(visited[x]) return false;
    visited[x] = true;
    for(int y: graph[x]){
        if(r[y] == -1 || dfs(r[y])){
            r[y] = x;
            l[x] = y;
            return true;
        }
    }
    return false;
}

int getIdx(int y, int x){
    return y * m + x;
}
bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<m && arr[y][x] == '.';
}
void solve(){
    cin>>n>>m;
    graph = vector<vector<int>>(n*m);
    int answer = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j] == '.') answer++;//후보군
        }
    }

    for(int y=0;y<n;y++){
        for(int x=0;x<m;x+=2){
            if(!pass(y,x)) continue;
            for(int i=0;i<6;i++){
                int yy = y + dy[i];
                int xx = x + dx[i];
                if(!pass(yy,xx)) continue;
                graph[getIdx(y,x)].push_back(getIdx(yy,xx));

            }
        }
    }
    l = vector<int>(n*m, -1);
    r = vector<int>(n*m, -1);
    for(int i=0;i<n*m; i++){
        visited = vector<bool>(n*m);
        if(dfs(i)) answer--;
    }

    cout<<answer<<'\n';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}