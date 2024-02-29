#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
using pii=pair<int,int>; 
int n,m, a,b,t;
vector<int> dist, track(1005);
vector<vector<pii>> graph(5005);
int banned_a, banned_b;
void dijkstra(int start){
	dist = vector<int>(n+1, INF);
	dist[start] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({dist[start], start});
	
	while(!pq.empty()){
		int distance = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if(dist[now] < distance) continue;
		
		for(int i=0;i<graph[now].size();i++){
			int next = graph[now][i].first;
			int next_distance = distance + graph[now][i].second;
			//통행 금지  도로 
			if(now==banned_a && next==banned_b || now==banned_b && next==banned_a) continue;
			
			if(next_distance < dist[next]){
				dist[next] = next_distance;
				pq.push({next_distance, next});
				track[next] = now;
			}
		}
	}
	
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b>>t;
		graph[a].push_back({b, t});
		graph[b].push_back({a, t});
	}
	dijkstra(1);
	
	vector<int> route;
	for(int i=n;i != 0;i = track[i])
		route.push_back(i);
		
	int original = dist[n];
	int answer = -1;
	
	for(int i=1;i<route.size();i++){
		banned_a = route[i-1];
		banned_b = route[i];
		dijkstra(1);
		answer = max(answer, dist[n]);
	}
	if(answer == INF) cout<<"-1";
	else cout<<answer - original;
	return 0;
}