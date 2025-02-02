#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;
struct Info{
    int b,c;
    bool operator<(const Info & other)const{
        return c > other.c;
    }
};
struct Edge{
    int a,b,c;
};

int n,m, s,d;
vector<vector<bool>>  deleted;
vector<vector<Info>> graph, reverse_graph;
vector<int> dist[2];
vector<Edge> edges;

void dijkstra(vector<vector<Info>>& graph, int start, vector<int>& dist){
    priority_queue<Info> pq;
    pq.push({start, 0});
    dist[start] = 0;

    while(!pq.empty()){
        int now = pq.top().b;
        int now_distance = pq.top().c;
        pq.pop();
        if(now_distance > dist[now]) continue;

        for(int i=0;i<graph[now].size();i++){
            int next = graph[now][i].b;
            int next_distance = now_distance + graph[now][i].c;
            if(deleted[now][next]) continue;
            if(next_distance >= dist[next]) continue;
            dist[next] = next_distance;
            pq.push({next, next_distance});
        }
    }
}
void findShortestPath(){
    for(auto edge: edges){
        if(dist[0][d] == dist[0][edge.a] + edge.c + dist[1][edge.b]){
            deleted[edge.a][edge.b] = true;
        }
    }
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    while(true){


        cin>>n>>m;
        if(n==0 && m==0) break;

        edges = vector<Edge>();
        dist[0] = dist[1] = vector<int>(n,INF);
        graph = reverse_graph = vector<vector<Info>>(n);
        deleted = vector<vector<bool>>(n, vector<bool>(n));
        cin>>s>>d;
        for(int i=0;i<m;i++){
            int a,b,c; cin>>a>>b>>c;
            graph[a].push_back({b,c});
            reverse_graph[b].push_back({a,c});
            edges.push_back({a,b,c});
        }
        dijkstra(graph, s, dist[0]);
        dijkstra(reverse_graph, d, dist[1]); //역방향 다익스트라
        findShortestPath(); //삭제간선 표시
        dist[0] = vector<int>(n,INF);
        dijkstra(graph, s, dist[0]);
        cout<<(dist[0][d]==INF ? -1 : dist[0][d])<<'\n';
    }
    return 0;
}