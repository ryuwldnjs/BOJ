#include <iostream>
#define INF 1'000'000'000
using namespace std;
int x,y,winning;

bool isDiff(int mid){
	int new_y = y + mid;
	int new_x = x + mid;
	int new_winning = 100LL*new_y/new_x;

	if(winning < new_winning) return true;
	return false;
}
int main(){
	cin>>x>>y;
	winning = 100LL*y/x;
	
	int l=0,r=INF;
	for(int i=0;i<100;i++){
		int mid = (l+r)/2;
		if(isDiff(mid)){
			r = mid;
		}
		else{
			l = mid+1;
		}
	}
	
	if(isDiff(l)) cout<<l;
	else if(isDiff(r)) cout<<r;
	else cout<<-1;
	return 0;
}