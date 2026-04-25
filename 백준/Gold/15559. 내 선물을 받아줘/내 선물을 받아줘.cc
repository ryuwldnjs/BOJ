#include <iostream>
using namespace std;

char map[1005][1005];
int parent[1005][1005];

int n,m,cnt;

int find(int ax, int ay){
	if(parent[ax][ay] < 0)
		return ax*1000 + ay;
	return parent[ax][ay] = find(parent[ax][ay]/1000, parent[ax][ay]%1000);
}
	
int merge(int ax, int ay, int bx, int by){
	int a = find(ax, ay);
	int b = find(bx, by);
	
	if(a == b) return 0;
	
	parent[a/1000][a%1000] += parent[b/1000][b%1000];
	parent[b/1000][b%1000] = a;
	return 1;
}
int main(){
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
		fill(parent[i], parent[i]+m+1, -1);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int ii,jj;
			if(map[i][j]=='N'){
				ii = i-1;
				jj = j;
			}
			else if(map[i][j]=='S'){
				ii = i+1;
				jj = j;
			}
			else if(map[i][j]=='W'){
				ii = i;
				jj = j-1;
			}
			else if(map[i][j]=='E'){
				ii = i;
				jj = j+1;
			}
			
			merge(i, j, ii, jj);
			
		}
	}
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(parent[i][j]<0) cnt++;
			
	cout<<cnt;
	return 0;
}