#include <iostream>
using namespace std;
int n,cnt;
int main(){
	cin>>n;
	n/=3;
	for(int i=1;i<=n-2;i++){
		for(int j=1;j+i<=n-1;j++){
			cnt++;
		//	printf("%d,%d,%d\n", i*3, j*3, 3*(n-i-j));
		}
	}
	cout<<cnt;
	return 0;
}