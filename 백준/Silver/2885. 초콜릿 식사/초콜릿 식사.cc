#include <iostream>
using namespace std;
int k,cnt, gap;
int main(){
	cin>>k;
	int squareBit = 0;
	while((1<<squareBit) < k){
		squareBit++;
	}
	
	for(int i=0;i<squareBit;i++){
		if(k & (1<<i)){
			gap = squareBit - i;
			break;
		}
	}
	cout<<(1<<squareBit)<<' '<<gap;
	return 0;
}