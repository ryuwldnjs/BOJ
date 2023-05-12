#include <iostream>
#include <queue>
using namespace std;
using pii = pair<int,int>;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

char map[1550][1550];
vector<pii> melt[2]; //얼음이 녹아버린 좌표들 인덱스2는 영향끼친 블럭의 좌표 
vector<pii> swan; //백조들 위치 
queue<pii> q, q_tmp;

int parent[1500*1500+50];
bool visited[1550][1550];

int r,c, day;
////////////////////////////////////////////////////////////////
int find(int x){
	if(parent[x] < 0) return x;
	return parent[x] = find(parent[x]);
}
bool merge(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return false;
	
	parent[a] += parent[b];
	parent[b] = a;
	return true;
}
//유니온파인드 
////////////////////////////////////////////////////////////////
bool pass(int x, int y){
	if(0<=x&&x<r && 0<=y&&y<c)
		return true;
	return false;
}



int main(){
	cin>>r>>c;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			parent[i*1500 + j] = -1; //자기자신이 루트 표시 
			cin>>map[i][j]; 
			if(map[i][j] == 'L') { 
				swan.push_back({i,j});
				map[i][j] = '.';

			}
			//tmp[i][j] = map[i][j];
			if(map[i][j] != 'X'){
				q_tmp.push({i, j});//녹을 수 있으면 일단 넣자
				visited[i][j] = true;
			} 
		}
	}
	
	
	while(true){
		int swan1 = 1500*swan[0].first + swan[0].second;
		int swan2 = 1500*swan[1].first + swan[1].second;
		
		q = q_tmp;
		q_tmp = queue<pii>();//녹게될 얼음들 초기화 
		melt[0] = vector<pii>();//녹은 후에 보일  임시 맵 초기화 
		melt[1] = vector<pii>();//녹은 후에 보일  임시 맵 초기화 
	
		while(!q.empty()){ //한번 돌면 하루가 지난 거임 

	
			int x = q.front().first;
			int y = q.front().second;
			
			q.pop();
			
			for(int i=0;i<4;i++){
				int xx = x + dx[i];
				int yy = y + dy[i];
				if(!pass(xx, yy)) continue; //맵 넘어서면 아웃 
				
//				merge(1500*x+y, 1500*xx+yy);//붙어있는 좌표들은 전부 union 

				if(map[xx][yy] == '.'){ //물끼리 인접 
					if(merge(1500*x+y, 1500*xx+yy) && find(swan1)==find(swan2)){
						cout<<day;
						return 0; 
					}
				}
				if(map[xx][yy] == '.' && find(swan1) == find(swan2)){
					cout<<day;
					return 0;
				} 
				
				//예외
				if(!visited[xx][yy]){
					if(map[xx][yy] == '.'){ // 물 
						q.push({xx, yy});

					}
					else{ //얼음 
						q_tmp.push({xx, yy});//다음 phase에선 얼음이 녹음 
						melt[0].push_back({xx, yy}); 
						melt[1].push_back({x, y});
					}
					visited[xx][yy] = true;
				}
				
			}
		}
		
		day++; //하루가 지남 
		if(find(swan1) == find(swan2)){
			cout<<day;
			return 0;
		}
		//printf("%d\n", day);
		for(int i=0;i<melt[0].size();i++){
			int x = melt[0][i].first;
			int y = melt[0][i].second;
			int xx = melt[1][i].first;
			int yy = melt[1][i].second;
			map[x][y] = '.';
			
			merge(1500*x+y, 1500*xx+yy);
		}
		
		//prev day에서 녹아버린 얼음들 반영
/*		printf("\n\nday:%d\n", day);
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				printf("%c", map[i][j]);
			}
			printf("\n");
		}
*/		
		
		
	//	day++;
		//백조가 하나의 컴포넌트에 있으면 만날 수 있다
			
	}
	return 0;
}