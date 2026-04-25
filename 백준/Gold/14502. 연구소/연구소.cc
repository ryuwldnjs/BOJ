#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int> > virus, space;
vector<vector<int> > map, visited;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int n,m;

//맵이탈 체크 
bool pass(int x, int y){
	return 0<=x&&x<n && 0<=y&&y<m;
}

//바이러스 전이 
int DFS(int x, int y){
	int infect=1;
	visited[x][y] = 2;
	
	for(int i=0;i<4;i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		
		if(pass(xx, yy) && visited[xx][yy] == 0)
			infect += DFS(xx, yy);
	}
	return infect;
}

int will, safety = -1;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n>>m;
	map.resize(n);
	
	for(int i=0;i<n;i++){
		map[i].resize(m);
		for(int j=0;j<m;j++){
			cin>>map[i][j];
			if(map[i][j] == 0) space.push_back({i,j});
			if(map[i][j] == 1) will++;
			if(map[i][j] == 2) virus.push_back({i,j});
		}
	}
	
	
	int sz = space.size();
	//빈공간중 임의의 3곳에 벽을 쌓기 
	for(int i=0;i<sz;i++){
		for(int j=i+1;j<sz;j++){
			for(int k=j+1;k<sz;k++){
				int total_virus = 0;
				map[space[i].first][space[i].second] = 1;
				map[space[j].first][space[j].second] = 1;
				map[space[k].first][space[k].second] = 1;
				
				visited = map;
				for(int v = 0;v<virus.size();v++)
					total_virus += DFS(virus[v].first, virus[v].second);
				safety = max(safety, n*m - (total_virus + will + 3));
				
				
				
				map[space[i].first][space[i].second] = 0;
				map[space[j].first][space[j].second] = 0;
				map[space[k].first][space[k].second] = 0;	
			}
		}
	}
	
	cout<<safety;
	return 0;
}