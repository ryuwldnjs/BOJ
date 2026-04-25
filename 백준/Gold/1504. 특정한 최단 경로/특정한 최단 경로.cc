#include <iostream>
#include <vector>
#include <queue> 
#define INF 987654321
using namespace std;
priority_queue <pair<int,int> > pq;
int n,e;
int a,b,c, v1, v2; 
int dist[3][800+5];
vector<vector<pair<int,int> > > vec;
void dijkstra(int start, int num){
	for(int i=1;i<=n;i++) dist[num][i] = INF;
	
	dist[num][start] = 0; 
	pq.push({-dist[num][start], start});
	
	while(!pq.empty()){
		int distance = -pq.top().first;
		int current = pq.top().second;
		pq.pop();
		if(dist[num][current] < distance) continue;
		
		
		for(int i=0;i<vec[current].size();i++){
			int next = vec[current][i].first;
			int next_distance = distance + vec[current][i].second;
			
			if(next_distance < dist[num][next]){
				dist[num][next] = next_distance;
				pq.push({-next_distance, next});
			}
		}
	}
}
int main(){
	cin>>n>>e;
	vec.resize(n+1);

	while(e--){
		cin>>a>>b>>c;
		vec[a].push_back({b, c});
		vec[b].push_back({a, c});
	}
	cin>>v1>>v2;
	
/*	dijkstra(1, 0);//시작점to중계지점 
	dijkstra(n, 1);//도착점to중계지점 
	dijkstra(a, 2);//중계to중계 
	int A = dist[0][v1];
	int B = dist[0][v2];
	int x = dist[3][b];
	int C = dist[1][v1];
	int D = dist[2][v2];*/
	dijkstra(v1, 0);
	dijkstra(v2, 1);
	int A = dist[0][1];//v1 to 1
	int B = dist[1][1];//v2 to 1
	int x = dist[0][v2];//v1 to v2
	int C = dist[0][n];//v1 to n
	int D = dist[1][n];//v2 to n
	if(A==INF || B==INF || x==INF || C==INF || D==INF) {
		cout<<-1;
		return 0;
	}
//	printf("%d %d %d %d %d", A, B, x, C, D);
	
	int ans = min(min(A+2*x+C, B+2*x+D), min(A+x+D, B+x+C));
	cout<<ans;
	return 0;
}