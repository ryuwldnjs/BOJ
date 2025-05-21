#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 1e9;
struct Info{
    int b,cost;
    bool operator<(const Info& other)const{
        return cost > other.cost;
    }
};

vector<vector<Info>> graph;
vector<int> parent(1000+5, -1);
void dijkstra(){
    priority_queue<Info> pq;
    vector<int> dist(1000+5, INF);
    pq.push({1, 0});
    dist[1] = 0;

    while(!pq.empty()){
        int now = pq.top().b;
        int now_dist = pq.top().cost;
        pq.pop();
        if(now_dist > dist[now]) continue;

        for(int i=0;i<graph[now].size();i++){
            int next = graph[now][i].b;
            int next_dist = now_dist + graph[now][i].cost;

            if(next_dist < dist[next]){
                dist[next] = next_dist;
                pq.push({next, next_dist});
                parent[next] = now;
            }
        }
    }

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,m;cin>>n>>m;
    graph.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    dijkstra();
    cout<<n-1<<'\n';
    for(int i=2;i<=n;i++){
        cout<<parent[i]<<' '<<i<<'\n';
    }
    return 0;
}