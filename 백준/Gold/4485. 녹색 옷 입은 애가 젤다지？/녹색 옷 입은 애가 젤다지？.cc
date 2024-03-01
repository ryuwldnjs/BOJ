#include <bits/stdc++.h>
#define INF 1e9 
using namespace std;
struct info{
	int x;
	int y;
	int distance;
	
	const bool operator<(const info other) const{
		return distance > other.distance;
	}
};

int n, graph[130][130];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
vector<vector<int>> dist;

bool pass(int x, int y){
	return 0<=x&&x<n && 0<=y&&y<n;
}

void dijkstra(int a, int b){
	dist = vector<vector<int>>(n, vector<int>(n,INF));
	dist[a][b] = graph[a][b];
	priority_queue<info> pq;
	pq.push({a,b,dist[a][b]});
	
	
	while(!pq.empty()){
		int x = pq.top().x;
		int y = pq.top().y;
		int distance = pq.top().distance;
		pq.pop();
		if(distance > dist[x][y]) continue;
		
		for(int i=0;i<4;i++){
			int xx = x + dx[i];
			int yy = y + dy[i];
			int next_distance = distance + graph[xx][yy];
			if(pass(xx,yy) && next_distance < dist[xx][yy]){
				pq.push({xx,yy,next_distance});
				dist[xx][yy] = next_distance;
			}
		}
	}
	return;
}
int main(){
	int tc=1;
	while(cin>>n){
		if(n==0) return 0;
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>graph[i][j];
			}
		}
		dijkstra(0,0);
		cout<<"Problem "<<tc++<<": "<<dist[n-1][n-1]<<'\n';
	}
	return 0;
}