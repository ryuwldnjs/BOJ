#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii=pair<int,int>;
struct Info{
    int a,b,cost;

    const bool operator<(const Info& other)const{
        return cost < other.cost;
    }
};

int n,m, map[15][15], visited[15][15];
int ans,cnt;
vector<Info> edges;

bool pass(int y, int x){
    return 0<=y&&y<n && 0<=x&&x<m;
}
void dfs(int y, int x, int num){
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    visited[y][x] = true;
    map[y][x] = num;
    for(int i=0;i<4;i++){
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(pass(yy,xx) && !visited[yy][xx] && map[yy][xx] == 1){
            dfs(yy,xx, num);
        }
    }
}

void connectEdge(int start_y, int start_x, int dy, int dx){
    int y=start_y, x=start_x, dist=0;
    vector<pii> pos;
    while(y<n && x<m){
        int yy = y + dy;
        int xx = x + dx;
        
        if(map[y][x] != map[yy][xx]){
            pos.push_back({yy,xx});
            //1, 4, 6
            //2, 3, 5, 6
        }
        y = yy;
        x = xx;
        if(y>=n && x>=m) break;
    }
    // for(int i=0;i<pos.size();i++){
    //     printf("%d %d\n", pos[i].first, pos[i].second);

    // }
    for(int i=1;i<pos.size();i++){
        if(map[pos[i].first][pos[i].second] == 0) continue;
        int dist = pos[i].first + pos[i].second - (pos[i-1].first + pos[i-1].second);
        if(dist <= 1) continue;

        int a = map[pos[i-1].first - dy][pos[i-1].second - dx];
        int b = map[pos[i].first][pos[i].second];
        edges.push_back({a,b, dist});
    }
}

vector<int> parent(10, -1);
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
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
        }
    }

    //set component number
    int num = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && map[i][j] == 1){
                dfs(i,j, num++);
            }
        }
    }
    connectEdge(0,9,1,0);
    //connect Bridge between islands horizontally
    for(int i=0;i<n;i++){
        connectEdge(i,0,0,1);   
    }
    //connect Bridge between islands vertically
    for(int i=0;i<m;i++){
        connectEdge(0,i,1,0);   
    }

    sort(edges.begin(), edges.end());
    for(auto edge: edges){
        // printf("%d %d %d\n", edge.a, edge.b, edge.cost);
        if(merge(edge.a, edge.b)){
            ans += edge.cost;
            cnt++;
            // printf("%d ", ans);
        }
    }
    if(cnt == num-2) cout<<ans;
    else cout<<-1;

    return 0;
}