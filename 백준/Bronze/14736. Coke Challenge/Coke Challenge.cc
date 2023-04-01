#include <iostream>
#define INF 1234567890
using namespace std;

int n,k,a,b,MIN = INF;
int main(){
	
	cin>>n>>k>>a;
	k /= a;
	
	for(int i=0;i<n;i++){
		cin>>a>>b;
		int remain = k - a;
		
		if(remain <= 0){	
			MIN = min(MIN, k);
			continue;
		}
		int ans = remain % a ? remain%a + b : 0;
		ans += (remain/a) * (a+b) + a;
		
		MIN = min(MIN, ans);
	}
	cout<<MIN;
	return 0;
}