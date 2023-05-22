#include <iostream>
using namespace std;

long long num, n, arr[6];
int main(){
	cin>>n;
	for(int i=0;i<6;i++){
		cin>>arr[i];
	}
	int start = n - (n%arr[5]) + 1;
	for(int i= start; i<=n;i++){
		if(i % arr[0] == 0) num = num + i;
		if(i % arr[1] == 0) num = num%i;
		if(i % arr[2] == 0) num = num&i;
		if(i % arr[3] == 0) num = num^i;
		if(i % arr[4] == 0) num = num|i;
		if(i % arr[5] == 0) num = num>>i;
	}
	cout<<num;
	return 0;
}