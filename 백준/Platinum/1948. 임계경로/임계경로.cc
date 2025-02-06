#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Info{
    int b, c;
    bool operator<(const Info& other)const{
        return c > other.c;
    }
};
int n,m,s,e;
int ans;
vector<int> dist, indegree;
vector<vector<Info>> graph, reverse_graph;
void topology(){
    priority_queue<Info> pq;
    pq.push({s,0});
    dist[s] = 0;
    while(!pq.empty()){
        int now = pq.top().b;
        int now_dist = pq.top().c;
        pq.pop();
        for(int i=0;i<graph[now].size();i++){
            int next = graph[now][i].b;
            int next_dist = now_dist + graph[now][i].c;
            dist[next] = max(dist[next], next_dist);
            if(--indegree[next] == 0){
                pq.push({next, dist[next]});
            }

        }
    }
}
void backtrack(int now, int cost){
    for(int i=0;i<reverse_graph[now].size();i++){
        int next = reverse_graph[now][i].b;
        int next_cost = reverse_graph[now][i].c;
        if(next_cost == -1) continue; //이미 지나온 간선 삭제
        reverse_graph[now][i].c = -1;
        
        if(dist[now] == dist[next] + next_cost){
            ans++;
            backtrack(next, dist[next]);
        }

    }
}
int main(){
    cin>>n>>m;
    graph = reverse_graph = vector<vector<Info>>(n+1);
    dist = indegree = vector<int>(n+1);
    for(int i=0;i<m;i++){
        int a,b,c; cin>>a>>b>>c;
        graph[a].push_back({b,c});
        reverse_graph[b].push_back({a,c});
        indegree[b]++;
    }
    cin>>s>>e;
    topology();
    backtrack(e, dist[e]);
    for(int i=1;i<=n;i++){
        // printf("%d ", dist[i]);
    }
    cout<<dist[e]<<'\n'<<ans;
    return 0;
}