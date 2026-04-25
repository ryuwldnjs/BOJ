#include <iostream>
#include <vector>
#include <queue>
#define INF 1234567890
using namespace std;
int m,n;
int from, to, cost;
vector<pair<int, int> > vec[1005];//간선 정보 
priority_queue<pair<int, int> > pq;
int dist[1005];

void dijkstra(int start){
	for(int i=1;i<=n;i++) dist[i] = INF;//초기 무한대 설정 
	
	dist[start] = 0; //시작점은 0
	pq.push({-dist[start], start});
	
	while(!pq.empty()){
		int distance = -pq.top().first;
		int current = pq.top().second;
		pq.pop();
		
		if(dist[current] < distance)
			continue;
			
		for(int i=0;i<vec[current].size();i++){
			int next = vec[current][i].first;
			int next_distance = distance + vec[current][i].second;
			
			if(next_distance < dist[next]){//갱신 가능 
				dist[next] = next_distance;
				pq.push({-next_distance, next});
			}
		}
		
		
	}
	
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int start, end;
	cin>>n>>m;

	for(int i=1;i<=m;i++){
		cin>>from>>to>>cost;
		vec[from].push_back({to, cost});
	}
	cin>>start>>end;
	dijkstra(start);
	
	cout<<dist[end];
	return 0;
}