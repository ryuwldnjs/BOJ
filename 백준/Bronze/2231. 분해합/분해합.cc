#include <stdio.h>
int n,ans;
int main(){
	scanf("%d", &n);
	
	for(int i=1;i<1000000;i++){
		int num=i,sum=i;
		while(num){
			sum+= num%10;
			num/=10;
		}
		//분해합 구하기 
		
		
		if(sum==n){
			ans = i;
			break;
		}
	}
	printf("%d", ans);
	return 0;
}