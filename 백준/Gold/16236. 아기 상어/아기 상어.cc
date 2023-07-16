#include <iostream>
#include <queue>
#define INF 100
using namespace std;
using pii=pair<int,int>;
queue<pii> q;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int n,map[25][25], time, cnt, level=2;
bool visited[25][25];
pii start, prey;


bool pass(int x, int y){
	return 0<=x&&x<n && 0<=y&&y<n && map[x][y] <= level;
}

int bfs(){
	int t=0;//먹이찾는데 걸리는 시간 
	while(!q.empty()){
		int sz = q.size();
		t++;
		while(sz--){//같은거리 정점들만 탐색 
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			
			for(int i=0;i<4;i++){
				int xx = x + dx[i];
				int yy = y + dy[i];
				
				if(pass(xx,yy) && !visited[xx][yy]){
					q.push({xx,yy});
					visited[xx][yy] = true;
					if(map[xx][yy]&&map[xx][yy] < level && (xx < prey.first || xx==prey.first&&yy<prey.second)){//잡아먹을수 있는것중 가장 우선순위 
						prey = {xx,yy};
					}
				}
			}
		}
		if(prey != make_pair(INF,INF)){//먹잇감 발견 
			map[prey.first][prey.second] = 0;
			start = prey; //다음 시작점 지정 
			time += t;
			return 1;
		}
	}
	return 0;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
			if(map[i][j] == 9 ) {
				start = {i,j};
				map[i][j] = 0;
			}
		}
	}
	
	while(true){
		q = queue<pii>();
		q.push(start);
		fill(&visited[0][0], &visited[24][24], 0);
		visited[start.first][start.second];
		prey = {INF, INF};//잡아먹을 먹이 위치 저장
		 
		if(bfs() == 0) break;//먹이 발견 못했을때 
		if(++cnt == level){//레벨업 조건 
			level++;
			cnt = 0;
		}
	}
	cout<<time;
	return 0;
}