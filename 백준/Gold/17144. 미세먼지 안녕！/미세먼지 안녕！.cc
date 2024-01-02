#include <iostream>
using namespace std;

int r,c,t;
int map[55][55], tmp[55][55];
int purifier, answer;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool pass(int x, int y){
	return 0<=x&&x<r && 0<=y&&y<c && map[x][y] != -1; 
}
void spread(int x, int y){
	int dust = map[x][y] / 5;
	for(int i=0;i<4;i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		
		if(pass(xx, yy)){
			tmp[xx][yy] += dust;
			tmp[x][y] -= dust;
		}
	}
}

void purify1(){
	int x,y;
	x = purifier-1;
	y = 0;
	while(x > 0){
		tmp[x][y] = tmp[x-1][y];
		x--;
	}
	while(y < c-1){
		tmp[x][y] = tmp[x][y+1];
		y++;
	}

	while(x < purifier){
		tmp[x][y] = tmp[x+1][y];
		x++;
	}
	while(y > 1){
		tmp[x][y] = tmp[x][y-1];
		y--;
	}
	tmp[x][y] = 0;
}

void purify2(){
	int x,y;
	x = purifier+2;
	y = 0;
	while(x < r-1){
		tmp[x][y] = tmp[x+1][y];
		x++;
	}

	while(y < c-1){
		tmp[x][y] = tmp[x][y+1];
		y++;
	}
	while(x > purifier+1){
		tmp[x][y] = tmp[x-1][y];
		x--;
	}
	while(y > 1){
		tmp[x][y] = tmp[x][y-1];
		y--;
	}

	tmp[x][y] = 0;
}


void update(){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			map[i][j] = tmp[i][j];
		}
	}
}


int main(){
	cin>>r>>c>>t;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>map[i][j];
			tmp[i][j] = map[i][j];
			if(tmp[i][j] == -1 && purifier==0) purifier = i;
		}
	}
	while(t--){
//		printf("\n");
		//1.미세먼지 확산 
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(map[i][j] > 0) spread(i,j);
			}
		}
		
		//2.공기청정기 작동
//		for(int i=0;i<r;i++){
//			for(int j=0;j<c;j++){
//				printf("%d ", tmp[i][j]);
////				answer += map[i][j];
//			}
//			printf("\n");
//		}
//		printf("---------------------------\n");
		purify1();
		purify2();
		update();
//		for(int i=0;i<r;i++){
//			for(int j=0;j<c;j++){
//				printf("%d ", map[i][j]);
////				answer += map[i][j];
//			}
//			printf("\n");
//		}
//		
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
//			printf("%d ", map[i][j]);
			answer += map[i][j];
		}
//		printf("\n");
	}
	cout<<answer+2;
	return 0;
}