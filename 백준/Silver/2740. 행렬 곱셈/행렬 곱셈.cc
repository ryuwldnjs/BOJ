#include <iostream>
using namespace std;
int n,m,k;
int A[105][105], B[105][105];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>A[i][j];
		}
	}
	
	cin>>m>>k;
	for(int i=0;i<m;i++){
		for(int j=0;j<k;j++){
			cin>>B[i][j];
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			int psum = 0;
			for(int dx=0;dx<m;dx++){
				psum += A[i][dx] * B[dx][j];
			}
			cout<<psum<<' ';
		}
		cout<<'\n';
	}
	
	return 0;
} 