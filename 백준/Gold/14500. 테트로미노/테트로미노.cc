#include <iostream>
#define INF 1234567890
using namespace std;
int tetro[19][4][4] ={
				 {{1,1,1,1},
				{0,0,0,0},
				{0,0,0,0},
				{0,0,0,0}},
				
				 {{1,0,0,0},
				{1,0,0,0},
				{1,0,0,0},
				{1,0,0,0}},
	// ㅡ모양	
				 {{1,1,0,0},
				{1,1,0,0},
				{0,0,0,0},
				{0,0,0,0}},
	// ㅁ모양 
				 {{1,0,0,0},
				{1,0,0,0},
				{1,1,0,0},
				{0,0,0,0}},
				 {{0,0,1,0},
				{1,1,1,0},
				{0,0,0,0},
				{0,0,0,0}},
				 {{1,1,0,0},
				{0,1,0,0},
				{0,1,0,0},
				{0,0,0,0}},
				 {{1,1,1,0},
				{1,0,0,0},
				{0,0,0,0},
				{0,0,0,0}},
	//ㄴ모양	 
				 {{0,1,0,0},
				{0,1,0,0},
				{1,1,0,0},
				{0,0,0,0}},
				 {{1,1,1,0},
				{0,0,1,0},
				{0,0,0,0},
				{0,0,0,0}},
				 {{1,1,0,0},
				{1,0,0,0},
				{1,0,0,0},
				{0,0,0,0}},
				 {{1,0,0,0},
				{1,1,1,0},
				{0,0,0,0},
				{0,0,0,0}},
	//ㄴ모양 대칭	
				 {{1,0,0,0},
				{1,1,0,0},
				{0,1,0,0},
				{0,0,0,0}},	 
				 {{0,1,1,0},
				{1,1,0,0},
				{0,0,0,0},
				{0,0,0,0}},	 
				 {{0,1,0,0},
				{1,1,0,0},
				{1,0,0,0},
				{0,0,0,0}},	 
				 {{1,1,0,0},
				{0,1,1,0},
				{0,0,0,0},
				{0,0,0,0}},
	//s모양 
				 {{1,1,1,0},
				{0,1,0,0},
				{0,0,0,0},
				{0,0,0,0}},	 
				 {{1,0,0,0},
				{1,1,0,0},
				{1,0,0,0},
				{0,0,0,0}},	 
				 {{0,1,0,0},
				{1,1,1,0},
				{0,0,0,0},
				{0,0,0,0}},	 
				 {{0,1,0,0},
				{1,1,0,0},
				{0,1,0,0},
				{0,0,0,0}}
	//ㅗ모양 
			};
			
int map[550][550];
int n,m;
int MAX = -INF;

//x,y기준으로 해당 모양의 블럭읗 놓고 얻을 수 있는 점수 
int calculate(int x, int y, int shape){
	int sum = 0;
	
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			sum += tetro[shape][i][j] * map[x+i][y+j];
			if(tetro[shape][i][j] && (x+i>=n || y+j>=m))//블럭이 맵을 뚫고 나갈때 
				return 0;
		}
	}
	return sum;
}

//(x,y)기준으로 19가지 블럭을 전부 대입해봄 
int solve(int x, int y){
	int MAX = -INF;
	for(int i=0;i<19;i++){
		MAX = max(MAX, calculate(x, y, i));
	}
	return MAX;
}


int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
		}
	}
	
	//(i,j)점마다 19가지 블럭을 모두 대입하여 최댓값 찾기 
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			MAX = max(MAX, solve(i, j));
		}
	}
	cout<<MAX;
	return 0;
}