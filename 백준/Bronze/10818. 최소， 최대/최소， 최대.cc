#include <iostream>
#define INF 1234567890

using namespace std;
int n,k;
int MIN=INF, MAX = -INF;
int main(){
	
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	
	cin>>n;
	while(n--){
		cin>>k;
		MIN = min(MIN, k);
		MAX = max(MAX, k);
	}
	
	cout<<MIN<<" "<<MAX;
	return 0;
}