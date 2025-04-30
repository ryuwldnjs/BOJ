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

vector<vector<Info>> graph;
int n,d,c; 
void dijkstra(){
    priority_queue<Info> pq;
    vector<int> dist(n+1, INF);
    pq.push({c, 0});
    dist[c] = 0;

    while(!pq.empty()){
        int now = pq.top().b;
        int distance = pq.top().cost;
        pq.pop();

        if(distance > dist[now]) continue;

        for(int i=0;i<graph[now].size();i++){
            int next = graph[now][i].b;
            int next_distance = graph[now][i].cost + distance;

            if(next_distance >= dist[next]) continue;

            pq.push({next, next_distance});
            dist[next] = next_distance;
        }
    }
    int cnt = 0;
    int MAX = -1;
    for(int i=1;i<=n;i++){
        if(dist[i] == INF) continue;
        MAX = max(MAX, dist[i]);
        cnt++;
    }
    cout<<cnt<<' '<<MAX<<'\n';
}
void solve(){
    cin>>n>>d>>c;
    graph = vector<vector<Info>>(n+1);

    for(int i=0;i<d;i++){
        int a,b,s; cin>>a>>b>>s;
        graph[b].push_back({a,s});
    }
    dijkstra();
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}