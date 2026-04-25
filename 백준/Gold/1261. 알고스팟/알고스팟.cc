#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;
int map[105][105];
int dist[105][105];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int m,n;
struct stats{
	int y, x;
	int d;
	bool operator()(const stats &a, const stats &b){
		return a.d < b.d;
	}
};

bool pass(int y, int x){
	return 0<=y&&y<n && 0<=x&&x<m;
}
priority_queue<stats, vector<stats>, stats> pq;
int main(){
	cin>>m>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) 
			scanf("%1d",&map[i][j]), dist[i][j] = INF;
		
		
	dist[0][0] = 0;
	pq.push({0,0,0});
	
	while(!pq.empty()){
		stats now = pq.top();
		pq.pop();
		
		
		for(int i=0;i<4;i++){
			int yy = now.y + dy[i];
			int xx = now.x + dx[i];
			int d = now.d + map[yy][xx];
			
			if(pass(yy,xx) && d < dist[yy][xx]){
				dist[yy][xx] = d;
				pq.push({yy,xx, d});
			}
		}
	}
	printf("%d", dist[n-1][m-1]);
	return 0;
}