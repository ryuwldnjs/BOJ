#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
vector<vector<int>> light(10, vector<int>(10)), tmp;
int dx[5] = {0,-1,0,1,0};
int dy[5] = {-1,0,0,0,1};
int answer = INF;

bool pass(int y, int x){
	return 0<=y&&y<10 && 0<=x&&x<10;
}

void switching(int y, int x){
	for(int i=0;i<5;i++){
		int yy = y + dy[i];
		int xx = x + dx[i];
		if(!pass(yy,xx)) continue;
		tmp[yy][xx] ^= 1;
	}
	return;
}

void turnOff(int bit){
	int cnt = 0;
	
	//y=0첫줄에 대해 1024가지 경우의 수 대입 
	for(int x=0;x<10;x++){
		if(bit&(1<<x)){
			switching(0,x);
			cnt++;
		}
	}
	
	for(int y=1;y<10;y++){
		for(int x=0;x<10;x++){
			if(tmp[y-1][x] == 0) continue;
			switching(y,x);
			cnt++;
		}
	}
	
	for(int x=0;x<10;x++)
		if(tmp[9][x]) return;
	answer = min(answer, cnt);
	return;
} 

int main(){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			char c;	cin>>c;
			if(c == 'O') light[i][j] = 1;
		}
	}
	
	for(int i=0;i<1024;i++){
		tmp = light;
		turnOff(i);//비트마스크 i 로 맨 첫줄 스위치 눌렀을때 
	}
	
	if(answer == INF) cout<<"-1";
	else cout<<answer; 
	return 0;
}