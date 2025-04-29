#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    int y,x;
    int keys; //6비트마스크
    int cost;
};
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};
int n,m;
char graph[55][55];
bool visited[55][55][1<<6];

bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<m && graph[y][x] != '#';
}

int bfs(Info start){
    queue<Info> q;
    q.push(start);

    while(!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        int keys = q.front().keys;
        int cost = q.front().cost;
        q.pop();
        if(graph[y][x] == '1') return cost;

        for(int i=0;i<4;i++){
            int yy = y + dy[i];
            int xx = x + dx[i];
            if(!pass(yy,xx)) continue;

            char next = graph[yy][xx];
            
            int next_keys = keys;
            //키 획득 가능
            if('a'<=next&&next<='f') next_keys |= (1 << (next - 'a'));

            if(visited[yy][xx][next_keys]) continue;

            //자물쇠가 아니거나 자물쇠여도 키가 있으면
            if(!('A'<=next&&next<='F') || (keys & (1<<(next - 'A')))){
                q.push({yy, xx, next_keys, cost + 1});
                visited[yy][xx][next_keys] = true;
            }
        }
    }
    return -1;
}

int main(){
    Info start;
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>graph[i][j];
            if(graph[i][j] == '0') start = {i,j,0,0};
        }
    }

    cout<<bfs(start);
    return 0;
}