#include <iostream>
#include <queue>
using namespace std;
int R,C;
char map[55][55];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
pair<int,int> goal;

bool pass(int y, int x){
	return 0<=y&&y<R && 0<=x&&x<C;
}
struct stats{
	int y,x,dist;
};
queue<stats> water, hedge;
int w_now_cnt, h_now_cnt, next_cnt;//현재 물시작점 개수, 다음 물시작점  개수 
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>R>>C;
	
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++){
			cin>>map[i][j];
			if(map[i][j]=='*') {
				water.push({i,j,0});
				w_now_cnt++;
			}
			if(map[i][j]=='S') {
				hedge.push({i,j,0});
				h_now_cnt++;
			}
			if(map[i][j]=='D') goal={i,j};
		}
		
		
	while(!hedge.empty()){
		for(int x=0;x<w_now_cnt;x++){//물이 불어나는 시작점들 
			stats now = water.front();
			water.pop();
			for(int i=0;i<4;i++){
				int yy = now.y + dy[i];
				int xx = now.x + dx[i];
				
				if(pass(yy,xx) && (map[yy][xx]=='.'||map[yy][xx]=='S')){
					water.push({yy,xx,0});
					map[yy][xx] = '*';
					next_cnt++;
				}
			}
			
		}
		
		//다음 phase 물 시작점개수 전달 
		w_now_cnt = next_cnt;
		next_cnt = 0;
		
		
		for(int x=0;x<h_now_cnt;x++){
			stats now = hedge.front();
			hedge.pop();
			
			//우리 고슴도치가 비버의 굴로 이동했어요!! 
			if(make_pair(now.y, now.x) == goal){
				cout<<now.dist;
				return 0;
			}
			
			
			for(int i=0;i<4;i++){
				int yy = now.y + dy[i];
				int xx = now.x + dx[i];
				int dist = now.dist;
				if(pass(yy,xx) && (map[yy][xx]=='.'||map[yy][xx]=='D')){
					hedge.push({yy,xx,dist+1});
					map[yy][xx] = 'S';
					next_cnt++;
				}
			}
		}
		
		
		//다음 phase 고슴도치 위치들 개수 전달 
		h_now_cnt = next_cnt;
		next_cnt = 0;
		
		/*
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++)
				printf("%c ",map[i][j]);
				printf("\n");
		}
		printf("\n");*/
		
	} 
	cout<<"KAKTUS";
	return 0;
}