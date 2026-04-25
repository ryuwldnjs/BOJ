#include <iostream>
using namespace std;
int a,b,c, arr[10];
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	
	cin>>a>>b>>c;
	int n = a*b*c;
	while(n){
		arr[n%10]++;
		n /= 10;
	}
	for(int i=0;i<10;i++)
		cout<<arr[i]<<'\n';
	return 0;
}