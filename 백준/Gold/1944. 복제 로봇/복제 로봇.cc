#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Edge{
    int a, b, cost;
    bool operator<(const Edge&other)const{
        return cost < other.cost;
    }
};
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

int n,m;
int board[55][55];
int keys[55][55];//해당조표의 키 번호
vector<pii> pos(1);
vector<Edge> edges;

void bfs(int sy, int sx, int start){
    bool visited[55][55]={};
    queue<Edge> q;
    q.push({sy,sx,0});
    
    while(!q.empty()){
        auto [y, x, cost] = q.front();
        q.pop();

        if(keys[y][x] != -1 && keys[y][x] != start){
            edges.push_back({start, keys[y][x], cost});
        }

        for(int i=0;i<4;i++){
            int yy = y + dy[i];
            int xx = x + dx[i];
            if(board[yy][xx] == 1 || visited[yy][xx]) continue;

            q.push({yy, xx, cost + 1});
            visited[yy][xx] = true;
        }
    }
}


vector<int> parent;
int find(int x){
    if(parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}

int merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return 0;
    parent[a] += parent[b];
    parent[b] = a;
    return 1;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    memset(keys, -1, sizeof(keys));
    parent.resize(m+1, -1);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c;cin>>c;
            if(c == 'S'){
                keys[i][j] = 0;
                pos[0] = {i,j};
            }
            if(c == 'K') {
                keys[i][j] = pos.size();
                pos.push_back({i,j});
            }
            if(c=='0') board[i][j] = 0;
            if(c=='1') board[i][j] = 1;
        }
    }


    //keys간의 그래프 형성
    for(int i=0;i<pos.size();i++){
        bfs(pos[i].first, pos[i].second, i);
    }


    sort(edges.begin(), edges.end());
    int answer = 0;
    for(auto [a, b, cost] : edges){
        if(merge(a, b)) answer += cost;
    }

    //모든 노드가 유니온 되지 않음
    if(-parent[find(0)] < m+1){
        cout<<-1;
        return 0;
    }

    cout<<answer;

    return 0;
}