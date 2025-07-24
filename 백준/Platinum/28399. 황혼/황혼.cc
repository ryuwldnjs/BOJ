#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define V0(v) (v * 2)
#define V1(v) (v * 2 + 1)
const ll INF = 1e17;

struct Info{
    int b;
    ll cost;

    bool operator<(const Info& other)const{
        return cost > other.cost;
    }
};

vector<vector<Info>> graph;
vector<ll> dist;

int n,m,k;

void dijkstra(){
    priority_queue<Info> pq;
    dist.resize(n*2+2, INF);
    dist[0] = 0;
    pq.push({0, 0});
    while(!pq.empty()){
        auto [now, cost] = pq.top();
        pq.pop();
        if(cost > dist[now]) continue;

        for(int i=0;i<graph[now].size();i++){
            int next = graph[now][i].b;
            ll next_cost = cost + graph[now][i].cost;

            if(next_cost < dist[next]){
                dist[next] = next_cost;
                pq.push({next, next_cost});
            }
        }
    }
}


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m>>k;
    graph.resize(n*2 + 2);

    //i로 들어오는 간선들 임시 저장
    vector<Info> indegree[2*100000+5];
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        indegree[b].push_back({a, c});
    }
    indegree[1].push_back({0, 0});

    for(int i=0;i<k;i++){
        int n;cin>>n;
        vector<int> path;
        for(int j=0;j<n;j++){
            int x;cin>>x;
            path.push_back(x);
        }
        for(int j=0;j<n;j++){
            if(j == 0){
                for(Info e: indegree[path[j]]){
                    graph[V0(e.b)].push_back({V1(path[j]), e.cost});
                    graph[V1(e.b)].push_back({V1(path[j]), e.cost});
                }
            }
            else if(j == n-1){
                for(Info e: indegree[path[j]]){
                    if(e.b != path[j-1])
                        graph[V1(e.b)].push_back({V0(path[j]), e.cost});
                    
                    graph[V0(e.b)].push_back({V0(path[j]), e.cost});
                }
            }
            else{
                for(Info e: indegree[path[j]]){
                    if(e.b == path[j-1]){
                        graph[V1(e.b)].push_back({V1(path[j]), e.cost});
                        graph[V0(e.b)].push_back({V0(path[j]), e.cost});
                    }
                    else{
                        graph[V1(e.b)].push_back({V0(path[j]), e.cost});
                        graph[V0(e.b)].push_back({V0(path[j]), e.cost});

                    }
                    
                }
            }
            indegree[path[j]].clear();

        }
    }

    //남은 간선들 처리
    for(int i=1;i<=n;i++){
        for(Info e: indegree[i]){
            graph[V0(e.b)].push_back({V0(i), e.cost});
            graph[V1(e.b)].push_back({V0(i), e.cost});
        }
    }

    dijkstra();


    for(int i=1;i<=n;i++){
        ll d = min(dist[V0(i)], dist[V1(i)]);
        if(d == INF) cout<<-1<<' ';
        else cout<<d<<' ';
    }
    return 0;
}