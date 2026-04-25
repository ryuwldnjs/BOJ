#include <iostream>
using namespace std;
int x,y;
int ans[4]={1,4,2,3}, idx; 
int main(){
	cin>>x>>y;
	if(x>0) idx = 0;
	else idx = 2;
	
	if(y<0) idx++;
	
	cout<<ans[idx];
	return 0;
}