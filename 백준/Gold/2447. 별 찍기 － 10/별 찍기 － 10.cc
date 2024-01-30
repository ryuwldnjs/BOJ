#include <iostream>
using namespace std;

int n;
char answer[2200][2200];
void solve(int x, int y, int size){
	if(size == 1){
		answer[x][y] = '*';
		return; 
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(i==1 && j==1) continue;
			solve(x + i*size/3, y + j*size/3, size/3);
		}
	}
}
int main(){
	fill(&answer[0][0], &answer[2199][2199], ' ');
	solve(0,0,2187);
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<answer[i][j];
		}
		cout<<'\n';
	}
	return 0;
}