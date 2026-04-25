#include <iostream>
#include <queue>
using namespace std;
int map[305][305];
bool visited[305][305];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int m,n,total;

bool pass(int y, int x){
	return 0<=y&&y<n && 0<=x&&x<m;
}

struct stats{
	int y,x;
	int h;
	bool operator < (const stats &b) const{
		return h > b.h; 
	}
};
priority_queue<stats> pq;

void DFS(int y, int x, int h){
	
	for(int i=0;i<4;i++){
		int yy = y + dy[i]; 
		int xx = x + dx[i];
		 
		if(pass(yy,xx) && !visited[yy][xx]){
			visited[yy][xx] = true;
			if(h > map[yy][xx]){
				total += h - map[yy][xx];
				DFS(yy, xx, h);
			}
			else{
				pq.push({yy,xx,map[yy][xx]});
			}
			
		}
	}
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>m>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
			if(i==0 || i==n-1 || j==0 || j==m-1)
				pq.push({i,j,map[i][j]});//가장자리부터 넣기 
		}
	}
	
	while(!pq.empty()){
		stats top = pq.top();
		pq.pop();
		visited[top.y][top.x] = true;
		DFS(top.y, top.x, top.h);
	}
	cout<<total;
	return 0;
}