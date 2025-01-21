#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Info{
    int to,cost;

    const bool operator<(const Info& other)const{
        return cost > other.cost;
    }
};

vector<vector<Info>> graph;
vector<int> dist;
int n,p,k;

void dijkstra(int val){
    dist = vector<int>(n+1, 1e9);
    priority_queue<Info> pq;
    dist[1] = 0;
    pq.push({1, 0});

    while(!pq.empty()){
        int now = pq.top().to;
        int now_distance = pq.top().cost;
        pq.pop();

        if(now_distance > dist[now]) continue;

        for(int i=0;i<graph[now].size();i++){
            int next = graph[now][i].to;
            int next_distance = now_distance + (graph[now][i].cost > val); // 임계치보다 크면, 가중치 부여

            if(next_distance >= dist[next]) continue;
            dist[next] = next_distance;
            pq.push({next, next_distance});
        }
    }
    return;
}

bool able(int val){
    dijkstra(val);
    // printf("%d\n", dist[n]);
    return dist[n] <= k;
}
int main(){
    cin>>n>>p>>k;
    graph.resize(n+1);

    for(int i=0;i<p;i++){
        int a,b,c; cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    // printf("%d", able(3));
    int l=0,r=2000000;
    for(int i=0;i<100;i++){
        int mid = (l+r)/2;
        if(able(mid)){
            r = mid;
        }
        else{ 
            l = mid;
        }
    }

    if(able(l)){
        cout<<l;
    }
    else if(able(r)){
        cout<<r;
    }
    else{
        cout<<-1;
    }

    return 0;
}