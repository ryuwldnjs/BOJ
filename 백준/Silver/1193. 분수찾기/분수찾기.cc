#include <iostream>
using namespace std;
int x,idx;
int main(){
	
	cin>>x;
	
	while(1){
		if(x - idx <= 0) break;
		x -= idx++;
	}
	
	if(idx % 2 == 1){
		cout<<idx - x +1<<'/'<<x;
	}
	else{
		cout<<x<<'/'<<idx - x + 1;
	}
	return 0;
}