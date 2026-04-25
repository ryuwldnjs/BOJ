#include <iostream>
using namespace std; 
int n,m;
int a,b,x,y, k;
int map[305][305];
int psum[305][305];
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>map[i][j];
			psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + map[i][j];			
		}
	}
	
	cin>>k;	
	while(k--){
		cin>>a>>b>>x>>y;
		cout<<psum[x][y] - psum[a-1][y] - psum[x][b-1] + psum[a-1][b-1]<<"\n";		
	}
	return 0;
}