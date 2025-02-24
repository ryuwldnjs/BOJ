#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;
struct Info{
    int b,c;
    bool operator<(const Info& other)const{
        return c > other.c;
    }
};

int n,m;
vector<vector<Info>> graph, new_graph;
vector<vector<int>> dist;
vector<int> price;
void dijkstra(int start, vector<vector<Info>>& graph, vector<int>& dist){
    priority_queue<Info> pq;
    dist[start] = 0;
    pq.push({start, 0});

    while(!pq.empty()){
        int now = pq.top().b;
        int now_distance = pq.top().c;
        pq.pop();

        if(dist[now] < now_distance) continue;

        for(int i=0;i<graph[now].size();i++){
            int next = graph[now][i].b;
            int next_distance = now_distance + graph[now][i].c;

            if(dist[next] <= next_distance) continue;
            dist[next] = next_distance;

            pq.push({next, next_distance});
        }
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    cin>>n>>m;
    graph.resize(n+1);
    new_graph.resize(n+1);
    dist.resize(n+1, vector<int>(n+1, INF));
    price.resize(n+1);

    for(int i=1;i<=n;i++){
        cin>>price[i];
    }
    for(int i=0;i<m;i++){
        int a,b,c; cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    
    for(int i=1;i<=n;i++){
        dijkstra(i, graph, dist[i]);
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            new_graph[i].push_back({j, price[i] * dist[i][j]});
        }
    }
    vector<int> answer(n+1, INF);
    dijkstra(1, new_graph, answer);
    cout<<answer[n];
    return 0;
}