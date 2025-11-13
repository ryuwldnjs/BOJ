#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    int b,cost;
    bool operator<(const Info& other)const{
        return cost > other.cost;
    }
};
const int INF = 1e9;
int n,m;
vector<Info> graph[1005];
bool visited[1005];

vector<pii> dijkstra(bool isTracked){
    priority_queue<Info> pq;
    vector<int> dist(n+1, INF);
    vector<int> track(n+1,-1);
    pq.push({1, 0});
    dist[1] = 0;

    while(!pq.empty()){
        auto [now, cost] = pq.top();
        pq.pop();

        if(cost > dist[now]) continue;

        for(int i=0;i<graph[now].size();i++){
            int next = graph[now][i].b;
            int next_cost = graph[now][i].cost + cost;

            if(next_cost >= dist[next]) continue;

            pq.push({next, next_cost});
            dist[next] = next_cost;
            track[next] = now;
            
        }
    }
    int i = n;
    vector<pii> routes;
    while(track[i] != -1){
        routes.push_back({i, track[i]});
        i = track[i];
    }
    return routes;
}

int dijkstra(int banA, int banB){
    priority_queue<Info> pq;
    vector<int> dist(n+1, INF);
    pq.push({1, 0});
    dist[1] = 0;

    
    while(!pq.empty()){
        auto [now, cost] = pq.top();
        pq.pop();

        if(cost > dist[now]) continue;

        for(int i=0;i<graph[now].size();i++){
            int next = graph[now][i].b;
            int next_cost = graph[now][i].cost + cost;

            if(next_cost >= dist[next]) continue;
            if(now==banA&&next==banB || now==banB&&next==banA) continue;

            pq.push({next, next_cost});
            dist[next] = next_cost;
            
        }
    }

    return dist[n];
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }


    vector<pii> routes = dijkstra(true);

    int answer = -1;
    for(auto [a,b] : routes){
        answer = max(answer, dijkstra(a,b));
    }

    cout<<answer;
    return 0;
}