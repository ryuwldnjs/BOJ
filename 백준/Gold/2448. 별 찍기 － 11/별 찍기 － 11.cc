#include <iostream>
using namespace std;

int n;
char map[4000][8000];
void init(){
	map[0][0] = map[0][1] = map[0][2] = map[0][3] = map[0][4] = '*';
	map[1][1] = map[1][3] = '*';
	map[2][2] = '*';
}
void copy(int size){ // 3, 6, 12, 24..
	int h = size;
	int w = 2 * size;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			map[i][j + w] = map[i][j]; //우측 
			map[i + h][j + w/2] = map[i][j];//상단 
		}
	}
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n;
	int k = 3;
	init();
	while(k <= n / 2){
		copy(k);
		k *= 2;
	}
	
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<2*n;j++){
			if(map[i][j] =='*') cout<<'*';
			else cout<<' ';
		}
		cout<<'\n';
	}
	return 0;
}