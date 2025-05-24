#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 1e9;
struct Info{
    int b,cost;
    int depth;
    bool operator<(const Info &other)const{
        return cost > other.cost;
    }
};
int n,m,k;
int s,d;
vector<vector<Info>> graph;
vector<vector<int>> dist;
void dijkstra(){
    priority_queue<Info> pq;
    dist = vector<vector<int>>(n+1, vector<int>(n+1, INF));
    pq.push({s, 0, 0});
    dist[s][0] = 0;
    while(!pq.empty()){
        int now = pq.top().b;
        int now_dist = pq.top().cost;
        int now_depth = pq.top().depth;
        pq.pop();
        if(now_depth >= n-1) continue;
        if(now_dist > dist[now][now_depth]) continue;

        for(int i=0;i<graph[now].size();i++){
            int next = graph[now][i].b;
            int next_dist = now_dist + graph[now][i].cost;
            if(next_dist < dist[next][now_depth + 1]){
                dist[next][now_depth + 1] = next_dist;
                pq.push({next, next_dist, now_depth + 1});
            }
        }
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m>>k;
    cin>>s>>d;

    graph.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    dijkstra();

    int increasing = 0;
    while(k-- >= 0){
        int MIN = INF;
        for(int i=1;i<n;i++){//목적지까지 i번 거쳐 갈때 최단거리
            MIN = min(MIN, dist[d][i] + increasing * i);
        }
        cout<<MIN<<'\n';
        int p; cin>>p;
        increasing += p;
    }
    return 0;
}