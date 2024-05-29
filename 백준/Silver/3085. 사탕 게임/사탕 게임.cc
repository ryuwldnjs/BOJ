#include <iostream>
using namespace std;
int n;
char m[55][55];
int answer;
int findLine(int y, int x){
	int MAX = 0;
	int cnt;
	cnt=1;
	for(int i=1;i<n;i++){
		if(m[y][i] == m[y][i-1]) cnt++;
		else cnt = 1;
		MAX = max(MAX, cnt);
	}
	cnt=1;
	for(int i=1;i<n;i++){
		if(m[i][x] == m[i-1][x]) cnt++;
		else cnt = 1;
		MAX = max(MAX, cnt);
	}
	cnt=1;
	for(int i=1;i<n;i++){
		if(y-1>=0 && m[y-1][i] == m[y-1][i-1]) cnt++;
		else cnt = 1;
		MAX = max(MAX, cnt);
	}
	cnt=1;
	for(int i=1;i<n;i++){
		if(x-1>=0 && m[i][x-1] == m[i-1][x-1]) cnt++;
		else cnt = 1;
		MAX = max(MAX, cnt);
	}
	return MAX;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>m[i][j];
		}
	}

	for(int i=0;i<n;i++){
		for(int j=1;j<n;j++){
			swap(m[i][j-1], m[i][j]);
			answer = max(answer, findLine(i,j));
			swap(m[i][j-1], m[i][j]);
		}
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<n;j++){
			swap(m[i-1][j], m[i][j]);
			answer = max(answer, findLine(i,j));
			swap(m[i-1][j], m[i][j]);			
		}
	}
	
	cout<<answer;
	return 0;
}