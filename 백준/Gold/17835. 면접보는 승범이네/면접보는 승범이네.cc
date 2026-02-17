#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;
#define INF 1e18

struct Info{
    ll b, cost;
    
    bool operator<(const Info& other)const{
        return cost > other.cost;
    }
};

ll n,m,k;
vector<vector<Info>> graph;

vector<ll> dijkstra(){
    priority_queue<Info> pq;
    vector<ll> dist(n+1, INF);
    dist[0] = 0;
    pq.push({0, 0});

    while(!pq.empty()){
        auto [now, cost] = pq.top(); pq.pop();

        if(dist[now] < cost) continue;

        for(ll i=0;i<graph[now].size();i++){
            ll next = graph[now][i].b;
            ll next_cost = graph[now][i].cost + cost;

            if(dist[next] <= next_cost) continue;
            dist[next] = next_cost;
            pq.push({next, next_cost});
        }
    }
    return dist;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m>>k;
    graph.resize(n+1);

    for(ll i=0;i<m;i++){
        ll a,b,c;cin>>a>>b>>c;
        graph[b].push_back({a,c});
    }
    for(ll i=0;i<k;i++){
        ll city;cin>>city;
        graph[0].push_back({city, 0});
    }

    vector<ll> dist = dijkstra();

    ll ans = 1;
    for(ll i=1;i<=n;i++){
        // printf("%d ",dist[i]);
        if(dist[ans] < dist[i]) ans = i;
    }

    cout<<ans<<'\n'<<dist[ans];
    return 0;
}