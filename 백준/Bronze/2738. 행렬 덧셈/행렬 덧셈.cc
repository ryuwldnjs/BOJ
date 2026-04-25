#include <iostream>
using namespace std;
int n,m;
int arr[105][105],k; 
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>arr[i][j];
			

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			cin>>k;
			arr[i][j] += k;
		}
		
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}