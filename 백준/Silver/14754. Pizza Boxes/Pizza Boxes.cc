#include <iostream>
using namespace std;
long long arr[1000+5][1000+5];
long long n,m,sum,tmp;
pair<int, int> front[1000+5], side[1000+5];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		//	sum+=arr[i][j];//최초상태 총합 
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]>arr[n][j]){
				arr[n][j] = arr[i][j];
				front[j]={i,j};
			}
			if(arr[i][j]>arr[i][m]){
				arr[i][m] = arr[i][j];
				side[i]={i,j};
			}
		}
	}
	
	
	for(int i=0;i<m;i++){
		int x =front[i].first;
		int y =front[i].second;
		arr[x][y]=0;

	}

	for(int i=0;i<n;i++){
		int x =side[i].first;
		int y =side[i].second;
		arr[x][y]=0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
		//	printf("%2d ", arr[i][j]);
			tmp+=arr[i][j];//max블럭이 제거된 상태 
		}
		//printf("\n");
	}
	cout<<tmp;
	return 0;
}