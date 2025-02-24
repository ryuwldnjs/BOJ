#include <iostream>
#include <vector>
#include <queue>
#define INF 1e18
using namespace std;
using ll=long long;

struct Info{
    ll b,c;
    bool operator<(const Info& other)const{
        return c > other.c;
    }
};

ll n,m;
vector<vector<Info>> graph, new_graph;
vector<vector<ll>> dist;
vector<ll> price;
void dijkstra(ll start, vector<vector<Info>>& graph, vector<ll>& dist){
    priority_queue<Info> pq;
    dist[start] = 0;
    pq.push({start, 0});

    while(!pq.empty()){
        ll now = pq.top().b;
        ll now_distance = pq.top().c;
        pq.pop();

        if(dist[now] < now_distance) continue;

        for(ll i=0;i<graph[now].size();i++){
            ll next = graph[now][i].b;
            ll next_distance = now_distance + graph[now][i].c;

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
    dist.resize(n+1, vector<ll>(n+1, INF));
    price.resize(n+1);

    for(ll i=1;i<=n;i++){
        cin>>price[i];
    }
    for(ll i=0;i<m;i++){
        ll a,b,c; cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    
    for(ll i=1;i<=n;i++){
        dijkstra(i, graph, dist[i]);
        for(ll j=1;j<=n;j++){
            if(i==j) continue;
            new_graph[i].push_back({j, price[i] * dist[i][j]});
        }
    }


    vector<ll> answer(n+1, INF);
    dijkstra(1, new_graph, answer);

    cout<<answer[n];
    return 0;
}