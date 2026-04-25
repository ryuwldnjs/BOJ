#include <iostream>
using namespace std;
int n,i;
int main(){
	cin>>n;
	for(i=1;n>1;i++)
		n -= 6*i;
	cout<<i;
	return 0;
}