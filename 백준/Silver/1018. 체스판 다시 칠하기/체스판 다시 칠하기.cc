#include <iostream>
#include <algorithm>
using namespace std;
char ulsan[8][8];
int n,m, MIN = 1234567890;
char map[55][55];

//해당 블럭에서 몇개를 색칠해야하는지????? 
int check(int x, int y){
	int cnt=0;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(map[x+i][y+j] != ulsan[i][j]) cnt++; //다르니까...고쳐야하니까.. 
		}
	}
	return cnt<64-cnt ? cnt : 64-cnt; // 흑백 바뀌었을시 개수 비교 
	
}
int main(){
	
	for(int i=0;i<8;i++){ //정답 체스판 생성 
		for(int j=0;j<8;j++){
			if((i+j)%2) ulsan[i][j] = 'B';
			else ulsan[i][j] = 'W';
		}
	}
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
		}
	}
	
	for(int i=0;i<n-7;i++){
		for(int j=0;j<m-7;j++){
			MIN = min(MIN, check(i,j));
		}
	}
	cout<<MIN;
	return 0;
} 