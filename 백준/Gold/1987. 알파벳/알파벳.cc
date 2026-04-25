#include <iostream>
using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
char map[25][25];

bool check[25]; //해당 알파벳을 썼는지 체크 
int answer;//최대 몇칸? 

int r,c;
bool pass(int x, int y){//주어진 맵을 벗어나는지 체크 
	if(0<=x&&x<r && 0<=y&&y<c)
		return true;
	return false;
}


void backtrack(int x, int y, int depth){
	answer = max(answer, depth);
	
	check[map[x][y]-'A'] = true;
	for(int i=0;i<4;i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		
		if(pass(xx, yy) && !check[map[xx][yy]-'A']){
			check[map[xx][yy]-'A'] = true;
			backtrack(xx, yy, depth+1);
			check[map[xx][yy]-'A'] = false;
		}
		
	}
}


int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false); 
	cin>>r>>c;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>map[i][j];
		}
	}
	backtrack(0,0, 1);
	cout<<answer;
	return 0;
}