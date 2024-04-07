#include <iostream>
#include <vector>
using namespace std;
int check_y[9], check_x[9], check_block[9];
vector<vector<int>> map(9, vector<int>(9)), answer(9, vector<int>(9));

bool isOff(int y, int x, int val){
	if(check_y[y]&(1<<val)) return false;
	if(check_x[x]&(1<<val)) return false;
	if(check_block[y/3*3 + x/3]&(1<<val)) return false;
	if(map[y][x]) return false;
	return true;
}

void switchBits(int y, int x, int val){
	check_y[y] ^= (1<<val);
	check_x[x] ^= (1<<val);
	check_block[y/3*3 + x/3] ^= (1<<val);
	map[y][x] ^= val;//스도쿠판에 값 기입 or 제거 
	return; 
}

int recur(int y, int x){
	//다음줄로 넘어감 
	if(x==9){
		y++;
		x = 0;
	}
	//마지막줄 마저 다 끝날때 
	if(y==9){
		answer = map;
		return 1;
	}
	
	if(map[y][x] && recur(y, x+1)) return 1; //이미 숫자 채워져 있으면 패스
	
	for(int i=1;i<=9;i++){
		if(isOff(y,x,i)){
			switchBits(y,x,i);
			if(recur(y, x+1)) return 1;
			switchBits(y,x,i);
		}
	}
	return 0;
}
int main(){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			int x; cin>>x;
			if(x) switchBits(i,j, x);
		}
	}
	
	recur(0,0);
	
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<answer[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}