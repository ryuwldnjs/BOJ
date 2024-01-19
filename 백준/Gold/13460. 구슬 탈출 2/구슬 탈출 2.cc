#include <iostream>
#include <queue>
#define W 1
#define N 2
#define E 3
#define S 4
using namespace std;
using pii=pair<int,int>;
pii R_pos, B_pos, goal;

struct Info{
	pii R;
	pii B;
	int phase;
	int dir;
};

char map[15][15];
int n,m;
queue<Info> q;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

bool pass(pii marble){
	return marble.first>=0 && marble.second>=0 && map[marble.first][marble.second] != '#';
}

Info move(pii R, pii B, int dir){
	dir--; //0인덱스 보정 
	
	while(true){
		bool able_R = false;
		bool able_B = false;
		
		pii next_R = {R.first + dx[dir], R.second + dy[dir]};
		pii next_B = {B.first + dx[dir], B.second + dy[dir]};
		
		if(next_R == B){ // B먼저 이동 
			if(pass(next_B)){
				B = next_B;
				able_B = true;
			}
			if(pass(next_R) && next_R != B){//B가 이동했을때만, 
				R = next_R;
				able_R = true;
			}
		}
		else{ // R먼저 이동 or 그 외 나머지 경우 
			if(pass(next_R)){
				R = next_R;
				able_R = true;
			}
			if(pass(next_B) && next_B != R){//B가 이동했을때만, 
				B = next_B;
				able_B = true;
			}
		}
		if(R == goal) R = {-1,-1};
		if(B == goal) B = {-1,-1};
		if(able_R==false && able_B==false) break;
	}
	
	Info result = {R, B, 0,dir};
	return result;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
			if(map[i][j] == 'B'){
				B_pos = {i,j};
				map[i][j] = '.';
			} 
			if(map[i][j] == 'R'){
				R_pos = {i,j};
				map[i][j] = '.';				
			}
			if(map[i][j] == 'O'){
				goal = {i,j};
				map[i][j] = '.';				
			}
		}
	}
	
	q.push({R_pos,B_pos, 0, 0});
	//시작할때 dir=0으로 두고, 나머지 방향은 1,2,3,4 
	while(!q.empty()){
		auto now = q.front();
		pii R = now.R;
		pii B = now.B;
		int phase = now.phase;
		int dir = now.dir;
		q.pop();
//		9printf("%d : %d,%d  %d,%d  %d\n", phase, R.first, R.second, B.first, B.second, dir); 
		if(R == make_pair(-1,-1)){
			cout<<phase;
			return 0;
		}
		
		if(phase==10) continue; 
		for(int i=1;i<=4;i++){
			auto next = move(R, B, i);
			if(dir != i && next.B != make_pair(-1,-1)) q.push({next.R, next.B, phase+1, i});
		}	
	}
	cout<<-1;
	return 0;
}