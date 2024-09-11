#include <iostream>
#include <queue>
#define INF 1e9
using namespace std;
using pii=pair<int,int>;
vector<int> dist;
vector<vector<pii>> graph;
priority_queue<pii, vector<pii>, greater<pii>> pq; // {거리, 노드번호}

int n,c;
void dijkstra(int start){
    pq.push({0, 0});
    dist = vector<int>(n, INF);
    dist[start] = 0;

    while(!pq.empty()){
        int now = pq.top().second;
        int distance = pq.top().first;
        pq.pop();
        if(dist[now] < distance) continue; //이미 지금 좌표는 최적화된듯
        
        for(int i=0;i<graph[now].size();i++){
            int next = graph[now][i].second;
            int next_distance = distance + graph[now][i].first;

            if(dist[next] <= next_distance) continue; // 갱신 필요 x
            dist[next] = next_distance;
            pq.push({next_distance, next});
        }
    }
}
int main(){
    cin>>n>>c;
    graph.resize(n);
    dist.resize(n);
    for(int i=0;i<c;i++){
        int t,a,b; cin>>t>>a>>b;
        graph[a].push_back({0, b}); // 포탈연결
        if(t == 1 && a+1 <= n-1) graph[a].push_back({1, a+1}); // 블루포탈은 x+1이동 경로 추가
    }
    for(int i=0;i<n-1;i++){
        if(graph[i].empty()) graph[i].push_back({1, i+1});
    }

    dijkstra(0);
    cout<<(dist[n-1] == INF ? -1 : dist[n-1]);
    return 0;
}