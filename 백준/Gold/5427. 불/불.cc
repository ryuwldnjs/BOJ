#include <iostream>
#include <queue>
using namespace std;
int R,C;
char map[1005][1005];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

bool pass(int y, int x){
	return 0<=y&&y<R && 0<=x&&x<C;
}
struct stats{
	int y,x,dist;
};
queue<stats> fire, sang;
int f_now_cnt, s_now_cnt, next_cnt;//현재 물시작점 개수, 다음 물시작점  개수 
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
	cin>>C>>R;
	while(!fire.empty()) fire.pop();
	while(!sang.empty()) sang.pop();
	f_now_cnt = s_now_cnt = next_cnt = 0;
	
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++){
			cin>>map[i][j];
			if(map[i][j]=='*') {
				fire.push({i,j,0});
				f_now_cnt++;
			}
			if(map[i][j]=='@') {
				sang.push({i,j,});
				s_now_cnt++;
			}
		}
		
		
	while(!sang.empty()){
		for(int x=0;x<f_now_cnt;x++){//물이 불어나는 시작점들 
			stats now = fire.front();
			fire.pop();
			for(int i=0;i<4;i++){
				int yy = now.y + dy[i];
				int xx = now.x + dx[i];
				
				if(pass(yy,xx) && (map[yy][xx]=='.'||map[yy][xx]=='@')){
					fire.push({yy,xx,0});
					map[yy][xx] = '*';
					next_cnt++;
				}
			}
			
		}
		
		//다음 phase 불 시작점개수 전달 
		f_now_cnt = next_cnt;
		next_cnt = 0;
		
		
		for(int x=0;x<s_now_cnt;x++){
			stats now = sang.front();
			sang.pop();
			
			//우리 상근이가 무사히 건물을 탈출 했어요!!!@! 
			if(now.y==0 || now.y==R-1 || now.x==0 || now.x==C-1){
				cout<<now.dist+1<<'\n';
				goto  quit;
			}
			
			
			for(int i=0;i<4;i++){
				int yy = now.y + dy[i];
				int xx = now.x + dx[i];
				int dist = now.dist;
				if(pass(yy,xx) && map[yy][xx]=='.'){
					sang.push({yy,xx,dist+1});
					map[yy][xx] = '@';
					next_cnt++;
				}
			}
		}
		
		
		//다음 phase 상근이 위치들 개수 전달 
		s_now_cnt = next_cnt;
		next_cnt = 0;
		
		/*
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++)
				printf("%c ",map[i][j]);
				printf("\n");
		}
		printf("\n");*/
		
	} 
	cout<<"IMPOSSIBLE\n";
	
	quit :;
	}
	
	return 0;
}