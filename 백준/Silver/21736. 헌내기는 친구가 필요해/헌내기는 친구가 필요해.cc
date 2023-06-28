#include <iostream>
using namespace std;
using pii=pair<int,int>;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
char map[605][605];
bool visited[605][605];
int n,m;
pii start;

bool pass(int x, int y){
	if(0<=x&&x<n && 0<=y&&y<m && map[x][y]!='X')
		return true;
	return false;
}

int dfs(int x, int y){
	int cnt = 0;
	visited[x][y] = true;
	if(map[x][y] == 'P') cnt++;
	
	for(int i=0;i<4;i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		
		if(pass(xx, yy) && !visited[xx][yy])
			cnt += dfs(xx, yy);
	}
	return cnt;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j]; 
			if(map[i][j] == 'I')
				start = {i, j};
		}
	}
	
	
	int answer = dfs(start.first, start.second);
	
	if(answer) cout<<answer;
	else cout<<"TT";
	return 0;
}