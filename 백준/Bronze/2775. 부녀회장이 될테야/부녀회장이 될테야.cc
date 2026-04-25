#include <iostream>
using namespace std;
int T,k,n; 
int map[15][15];
int main(){
	cin>>T;
	for(int i=0;i<=14;i++){
		for(int j=1;j<=14;j++){
			map[i][j] = !i ? j : map[i][j-1] + map[i-1][j];
			
			
		}
	}
	
	
	while(T--){
		cin>>k>>n;
		cout<<map[k][n]<<'\n';
	}
	return 0;
}