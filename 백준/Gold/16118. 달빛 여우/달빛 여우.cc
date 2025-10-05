#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    int b,cost;
    bool boost;
    bool operator<(const Info &other)const{
        return cost > other.cost;
    }
};
const int INF = 1e9;

int n,m;
vector<vector<Info>> graph;

//여우
void dijkstra(vector<int> &dist){
    dist.resize(n+1, INF);
    dist[1] = 0;
    priority_queue<Info> pq;
    pq.push({1, 0});

    while(!pq.empty()){
        auto [now, cost, _] = pq.top();
        pq.pop();

        if(dist[now] < cost) continue;

        for(int i=0;i<graph[now].size();i++){
            int next = graph[now][i].b;
            int next_cost = cost + graph[now][i].cost;
            
            if(dist[next] <= next_cost) continue;
            pq.push({next, next_cost});
            dist[next] = next_cost;
        }
    }

}

//늑대
void dijkstra(vector<int> *dist, bool isWolf){
    dist[0].resize(n+1, INF);//부스트x
    dist[1].resize(n+1, INF);//부스트o
    dist[0][1] = 0;

    priority_queue<Info> pq;
    pq.push({1, 0, false});

    while(!pq.empty()){
        auto [now, cost, boost] = pq.top();
        pq.pop();

        if(dist[boost][now] < cost) continue;

        for(int i=0;i<graph[now].size();i++){
            int next = graph[now][i].b;
            int next_cost = cost;

            //now를 부스트써서 왔으면, next로 갈때는 느리게 가야댐
            if(boost) next_cost += graph[now][i].cost * 2;
            else next_cost += graph[now][i].cost / 2;

            if(dist[!boost][next] <= next_cost) continue;

            pq.push({next, next_cost, !boost});
            dist[!boost][next] = next_cost;
        }
    }
}


vector<int> fox, wolf[2];


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    graph.resize(n+1);

    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        graph[a].push_back({b, c*2});
        graph[b].push_back({a, c*2});
    }


    dijkstra(fox);
    dijkstra(wolf, true);


    int answer = 0;

    for(int i=1;i<=n;i++){
        if(fox[i] < min(wolf[0][i], wolf[1][i])) answer++;
    }
    cout<<answer;
    return 0;
}