#include <iostream>
#include <queue>
using namespace std;
struct Info{
	int val;
	int x;
	int y;
	bool operator<(const Info& tmp) const{
		return val > tmp.val;
	}
};
priority_queue<Info> pq;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int n,m,map[1005][1005], visited[1005][1005];
vector<vector<int>> answer;

bool pass(int x, int y){
	return 0<=x&&x<n && 0<=y&&y<m;
}
int dfs(int x, int y, int notVisited, int val){
	visited[x][y]++;
	int aroundMax = -1;
	if(notVisited == 1) answer[x][y] = val;//정답 행렬 생성 
	
	for(int i=0;i<4;i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(pass(xx,yy)){
			aroundMax = max(aroundMax, answer[xx][yy]);//컴포넌트 주변에서 최댓값 찾기 
			if(map[x][y]==map[xx][yy] && visited[xx][yy] == notVisited){
				aroundMax = max(aroundMax, dfs(xx,yy,notVisited, val));
			}
		}
	}
	return aroundMax;
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	answer = vector<vector<int>>(n, vector<int>(m,-1));	
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
			pq.push({map[i][j], i,j});
		}
	}
	while(!pq.empty()){
		int val = pq.top().val;
		int x = pq.top().x;
		int y = pq.top().y;
		pq.pop();
		if(visited[x][y]) continue;
		
		//첫번째로 컴포넌트 방문시, 인근 값중 가장 큰거 찾고 
		int aroundMax = dfs(x,y, 0, 0);
		//두번째로 컴포넌트 방문시, 정답행렬 구성 
		dfs(x,y, 1, aroundMax+1);
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<answer[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}