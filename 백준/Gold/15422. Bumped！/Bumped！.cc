#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;
const ll INF = (ll)1e13;
struct Info{
    ll b,cost;
    bool operator<(const Info& other)const{
        return cost > other.cost;
    }
};
ll n,m,f,s,t;
vector<vector<Info>> graph;
vector<ll> dijkstra(ll start){
    vector<ll> dist(n, INF);
    priority_queue<Info> pq;
    pq.push({start, 0});
    dist[start] = 0;

    while(!pq.empty()){
        ll now = pq.top().b;
        ll now_dist = pq.top().cost;
        pq.pop();
        if(now_dist > dist[now]) continue;


        for(ll i=0;i<graph[now].size();i++){
            ll next = graph[now][i].b;
            ll next_dist = now_dist + graph[now][i].cost;

            if(next_dist < dist[next]){
                dist[next] = next_dist;
                pq.push({next, next_dist});
            }
        }
    }
    return dist;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m>>f>>s>>t;
    graph.resize(n);
    for(ll i=0;i<m;i++){
        ll a,b,c;cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    vector<ll> dist_start, dist_end;
    dist_start = dijkstra(s);
    dist_end = dijkstra(t);

    ll answer = dist_start[t];
    // ll answer = INF;
    for(ll i=0;i<f;i++){
        ll a,b;cin>>a>>b;
        answer = min(answer, dist_start[a] + dist_end[b]);
        //answer = min(answer, dist_start[b] + dist_end[a]);
    }
    cout<<answer;
    return 0;
}