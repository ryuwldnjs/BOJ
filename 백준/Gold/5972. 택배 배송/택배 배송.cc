#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9
using namespace std;
struct Info{
	int b, cost;
	const bool operator<(const Info& other)const{
		return cost > other.cost;
	}
};
vector<int> dist;
vector<vector<Info>> graph;
int n,m;
void dijkstra(){
	priority_queue<Info> pq;
	pq.push({1, 0});
	dist[1] = 0;
	
	while(!pq.empty()){
		int now = pq.top().b;
		int now_distance = pq.top().cost;
		pq.pop();
		if(now_distance > dist[now]) continue;
		for(int i=0;i<graph[now].size(); i++){
			int next = graph[now][i].b;
			int next_distance = now_distance + graph[now][i].cost;
			
			if(next_distance < dist[next]){
				pq.push({next, next_distance});
				dist[next] = next_distance;
			}
			
		}
	}
}
int main(){
	cin>>n>>m;
	graph.resize(n+1);
	dist.resize(n+1, INF);
	for(int i=0;i<m;i++){
		int a,b,c; cin>>a>>b>>c;
		graph[a].push_back({b,c});
		graph[b].push_back({a,c});
	}
	dijkstra();
	cout<<dist[n];
	return 0;
}