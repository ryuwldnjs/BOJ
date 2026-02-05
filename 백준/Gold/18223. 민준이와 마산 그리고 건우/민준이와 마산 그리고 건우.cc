#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define INF 1e9

struct Info{
    int b,cost;
    bool operator<(const Info& other)const{
        return cost > other.cost;
    }
};

vector<vector<Info>> graph;
int v,e,p;

vector<int> dijkstra(int start){
    vector<int> dist(v+1, INF);
    priority_queue<Info> pq;
    dist[start] = 0;
    pq.push({start, 0});

    while(!pq.empty()){
        auto [now, cost] = pq.top(); pq.pop();

        if(cost > dist[now]) continue;

        for(int i=0;i<graph[now].size();i++){
            int next = graph[now][i].b;
            int next_cost = cost + graph[now][i].cost;

            if(next_cost >= dist[next]) continue;

            dist[next] = next_cost;
            pq.push({next, next_cost});
        }
    }

    return dist;
}


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>v>>e>>p;
    graph.reserve(v+1);

    for(int i=0;i<e;i++){
        int a,b,c;cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    vector<int> dist_minjun = dijkstra(1);
    vector<int> dist_gunwoo = dijkstra(p);

    if(dist_minjun[v] == dist_gunwoo[1] + dist_gunwoo[v]) cout<<"SAVE HIM";
    else cout<<"GOOD BYE";

    return 0;
}