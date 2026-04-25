#include<iostream>
using namespace std;

int n;
int sum,ans;
int main(){
	for(int i=0;i<10;i++){
		cin>>n;
	//	printf("\n%d %d\n", sum, n);
		if(sum+n > 100){ // 임계점 
			if(sum+n-100 <= 100-sum)
				ans = sum+n;
			else ans = sum;
			break;
		}
		
		sum+=n; 
		ans = sum;
	}
	
	cout<<ans;
	return 0;
}