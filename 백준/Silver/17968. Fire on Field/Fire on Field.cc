#include <iostream>
using namespace std;
int n,flag;
int a[1000+5] = {1,1};
int main(){
	cin>>n;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i] = j;
			flag=0;
			for(int k=1;i-2*k>=0;k++){
				if(a[i]-a[i-k]==a[i-k]-a[i-2*k]){
					flag=1;
					break;
				}				
				
			}
			if(!flag) break;
			
		}
	}
	printf("%d",a[n]);
	return 0;
}