#include <iostream>
#include <string>
using namespace std;

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};
string MOBIS = "MOBIS";
int n;
char map[105][105];
int answer;
bool pass(int y,int x){
	return 0<=y&&y<n && 0<=x&&x<n;
}
int find(int y, int x){
	int answer = 0;
	for(int dir=0;dir<8;dir++){
		bool isAnswer = true;
		for(int i=0;i<5;i++){
			int yy = y + dy[dir] * i;
			int xx = x + dx[dir] * i;
			if(!pass(yy,xx) || map[yy][xx] != MOBIS[i]) 
				isAnswer = false;
		}
		if(isAnswer) answer++;
	}
	return answer;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			answer += find(i,j);
		}
	}
	cout<<answer;
	return 0;
}