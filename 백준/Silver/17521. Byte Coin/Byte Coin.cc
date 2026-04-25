#include <stdio.h>
long long n,money;//요일수, 초기현금
long long price[20];
long long coin;
int main(){
	scanf("%lld %lld", &n, &money);
	for(int i=0;i<n;i++){
		scanf("%lld", &price[i]);
	}
	
	if(price[0]<price[1]){ //증가 추세일때 
		coin += money/price[0];
		money%=price[0];
	}
	
	for(int i=1;i<n-1;i++){
		if(price[i-1]<=price[i]&&price[i]>=price[i+1]){//극댓값 
			money+= coin*price[i];
			coin=0;
		}
		if(price[i-1]>=price[i]&&price[i]<=price[i+1]){//극솟값 
			coin+= money/price[i];
			money%=price[i];
		}
	}
	money+= coin*price[n-1];
	coin=0;
	printf("%lld", money);
	return 0;
}