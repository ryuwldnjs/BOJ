#include <iostream>
#include <set>
using namespace std;


int n,m,map[1005][1005];
int visited[1005][1005];
int group[500000];
int idx;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
bool pass(int x, int y){
	return 0<=x&&x<n && 0<=y&&y<m && map[x][y]==0;
}
void dfs(int x, int y, int idx){
	visited[x][y] = idx;
	group[idx]++;//idx번째 영역 추가 
	
	for(int i=0;i<4;i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(pass(xx, yy) && !visited[xx][yy]) dfs(xx,yy,idx);
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%1d", &map[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!visited[i][j] && map[i][j]==0){
				dfs(i,j, ++idx);
				
			}
		}
	}
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
//			printf("%d",visited[i][j]);
			if(map[x][y]==0){
				printf("0");
				continue;
			}
			set<int> adj_idx;
			int answer=0;
			for(int dir=0;dir<4;dir++){
				int xx = x + dx[dir];
				int yy = y + dy[dir];
				if(pass(xx,yy)){
					int group_idx = visited[xx][yy];
					adj_idx.insert(group_idx);
				}
			}
			for(auto idx : adj_idx){
				answer += group[idx];
			}
			
			printf("%d",(answer+1)%10);
		}
		printf("\n");
	}
	return 0;
}