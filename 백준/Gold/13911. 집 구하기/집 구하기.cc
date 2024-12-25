#include <iostream>
#include <vector>
#include <queue>
#define MACNAL (v+1)
#define SBUK (v+2)
#define INF 1e9
using namespace std;
struct Info{
    int b, cost;
    const bool operator<(const Info &other)const{
        return cost > other.cost;
    }
};

vector<vector<Info>> graph;
vector<bool> isHome;
vector<int> MAC_dist, STAR_dist;
int v,e;
int m,x,s,y;
int MIN = INF;
void dijkstra(int start, vector<int>& dist){
    priority_queue<Info> pq;
    pq.push({start, 0});
    dist = vector<int>(v+1 + 2, INF);
    dist[start] = 0;

    while(!pq.empty()){
        int now = pq.top().b;
        int now_distance = pq.top().cost;
        pq.pop();
        if(dist[now] < now_distance) continue; //이미 최단경로

        for(int i=0;i<graph[now].size();i++){
            int next = graph[now][i].b;
            int next_distance = now_distance + graph[now][i].cost;

            if(dist[next] <= next_distance) continue; //이미 최단경로
            
            dist[next] = next_distance;
            pq.push({next, next_distance});
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>v>>e;
    graph.resize(v+1 + 2); // 컨트롤타워 포함
    isHome.resize(v+1, true);
    for(int i=0;i<e;i++){
        int a,b,c; cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    cin>>m>>x;
    for(int i=0;i<m;i++){
        int target; cin>>target;
        graph[MACNAL].push_back({target,0});
        isHome[target] = false;
    }
    
    cin>>s>>y;
    for(int i=0;i<s;i++){
        int target; cin>>target;
        graph[SBUK].push_back({target,0});
        isHome[target] = false;
    }
    
    dijkstra(MACNAL, MAC_dist);
    dijkstra(SBUK, STAR_dist);

    for(int i=1;i<=v;i++){
        if(!isHome[i]) continue;
        if(MAC_dist[i] <= x && STAR_dist[i] <= y){
            MIN = min(MIN, MAC_dist[i] + STAR_dist[i]);
        }
    }

    cout<<(MIN==INF ? -1 : MIN);
    return 0;
}