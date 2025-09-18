#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

vector<int> graph[305];
vector<int> l, r;
vector<bool> visited;

bool dfs(int x){
    if(visited[x]) return false;
    visited[x] = true;
    for(int y: graph[x]){
        if(r[y] == -1 || dfs(r[y])){
            l[x] = y;
            r[y] = x;
            return true;
        }
    }
    return false;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int R,C,n;cin>>R>>C>>n;
    l.resize(R+1,-1);
    r.resize(C+1,-1);

    int board[305][305]={};
    for(int i=0;i<n;i++){
        int y,x;cin>>y>>x;
        board[y][x] = -1;
    }


    int idx = 0;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            if(board[i][j] == -1) continue;
            graph[i].push_back(j);
        }
    }

    int answer = 0;
    for(int i=1;i<=R;i++){
        visited = vector<bool>(R+1);
        if(dfs(i)) answer++;
    }
    cout<<answer;
    return 0;
}