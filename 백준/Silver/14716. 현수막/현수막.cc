#include <iostream>
using namespace std;

int m,n,map[255][255];
int cnt;
int dx[8]={-1,0,1,1,1,0,-1,-1};
int dy[8]={1,1,1,0,-1,-1,-1,0};
void dfs(int x, int y){
	map[x][y] = 0;
	for(int i=0;i<8;i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(map[xx][yy])
			dfs(xx,yy);
	}
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)
			cin>>map[i][j];
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)
			if(map[i][j]==1){
				dfs(i,j);
				cnt++;
			}
	}
	
	cout<<cnt;
	return 0;
} 