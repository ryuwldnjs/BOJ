#include <iostream>
#include <queue>
#include <cmath>
#define INF (double)1000000000

using namespace std;
using pdi=pair<double, int>;
priority_queue<pdi, vector<pdi>, greater<pdi>> pq;

vector<vector<pdi>> graph; // graph[i] : i와 연결된 거리,정점 
double dist[105];

pair<double,double> arr[105];
int n; 

double dijkstra(int start){
	for(int i=0;i<n;i++){
		dist[i] = INF;
	}
	
	dist[start] = 0;
	pq.push({dist[start], start});
	
	while(!pq.empty()){
		double cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		
		if(dist[now] < cost)
			continue;
		
		for(int i=0;i<graph[now].size();i++){
			double next_cost = cost + graph[now][i].first;
			int next = graph[now][i].second;
			
			if(next_cost < dist[next]){
				dist[next] = next_cost;
				pq.push({next_cost, next});
			}
		}
	}
	
	
	return dist[1];
}
int main(){
	cin>>arr[0].first>>arr[0].second;
	cin>>arr[1].first>>arr[1].second;
	cin>>n;
	n+=2;
	
	for(int i=2;i<n;i++){
		cin>>arr[i].first >> arr[i].second;
	}
	
	
	graph.resize(n);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			double dd = (arr[i].first-arr[j].first)*(arr[i].first-arr[j].first) + (arr[i].second-arr[j].second)*(arr[i].second-arr[j].second);
			double d = sqrt(dd);
			
			double cost = min(2 + abs((d-50)/5.0), d/5.0); //			
			if(i==0 || i==1) graph[i].push_back({d/5.0, j});//시작점,끝에선 걸어가야함
			else graph[i].push_back({cost, j});
			
			if(j==0 || j==1) graph[j].push_back({d/5.0, i});
			else graph[j].push_back({cost, i});
			
		}
	}
	cout<<dijkstra(0)<<'\n';
	for(int i=0;i<n;i++)
	//printf("%d:%lf\n", i,dist[i]);	
	return 0;
}