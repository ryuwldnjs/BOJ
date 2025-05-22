#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;
const ll INF = 1e18;
struct Info{
    ll b, cost;
    bool operator<(const Info &other)const{
        return cost > other.cost;
    }
};
ll n,m,d,e;

vector<vector<Info>> graph;
vector<ll> dijkstra(ll start){
    priority_queue<Info> pq;
    vector<ll> dist(n+1, INF);
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
    cin>>n>>m>>d>>e;
    vector<ll> height(n+1);
    graph.resize(n+1);

    for(ll i=1;i<=n;i++){
        cin>>height[i];
    }
    for(ll i=0;i<m;i++){
        ll a,b,c;cin>>a>>b>>c;
        if(height[a] > height[b]) swap(a,b);
        if(height[a] == height[b]) continue;
        graph[a].push_back({b,c});
        // graph[b].push_back({a,c});
    }

    vector<ll> distHome = dijkstra(1);
    vector<ll> distUniv = dijkstra(n);

    ll answer = -INF;
    for(ll i=2;i<n;i++){
        if(distHome[i]==INF || distUniv[i]==INF) continue;
        ll val = height[i] * e;
        val -= (distHome[i] + distUniv[i]) * d;
        answer = max(answer, val);
    }
    if(answer == -INF) cout<<"Impossible";
    else cout<<answer;
    return 0;
}