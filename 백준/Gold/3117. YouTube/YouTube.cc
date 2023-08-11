#include <iostream>
using namespace std;

int n,k,m,start[100000+5];
int p, parent[100000+5][35];
int main(){
	cin>>n>>k>>m;
	for(int i=0;i<n;i++){
		cin>>start[i];
	}
	
	
	
	for(int i=1;i<=k;i++){
		cin>>p;
		parent[i][0] = p;
	}
	for(int i=1;i<33;i++){
		for(int j=1;j<=k;j++){
			parent[j][i] = parent[parent[j][i-1]][i-1];
		}
	}
	
	for(int i=0;i<n;i++){
		int tmp = m-1;
		int p = start[i];
		for(int k=0;tmp;k++){
			if(tmp % 2 == 1) p = parent[p][k];
			tmp /= 2;
		}
		
		cout<<p<<' ';
	}
	return 0;
}