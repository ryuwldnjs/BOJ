#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    int row; //가상 row 숫자
    int col; //가상 col 숫자
};
Info info[105][105];
vector<vector<int>> graph;
vector<int> l,r;
vector<bool> visited;


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

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    char a[105][105];
    int n;cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    int idx = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j] == 'X') idx++;
            else{
                info[i][j].row = i + idx;
            }
        }
    }
    int SIZE = n + idx;
    graph.resize(SIZE);
    l.resize(SIZE, -1);

    idx = 0;
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            if(a[i][j] == 'X') idx++;
            else{
                info[i][j].col = j + idx;
            }
        }
    }
    r.resize(n + idx, -1);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j] == 'X') continue;
            int x = info[i][j].row;
            int y = info[i][j].col;

            graph[x].push_back(y);
        }
    }


    int answer = 0;
    for(int i=0;i<SIZE;i++){
        visited = vector<bool>(SIZE);
        if(dfs(i)) answer++;
    }
    cout<<answer;
    return 0;
}