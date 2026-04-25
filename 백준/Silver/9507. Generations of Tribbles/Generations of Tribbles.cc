#include <stdio.h>
long long koong[75]={1,1,2,4};
int t,n;
int main(){
	for(int i=4;i<68;i++){
		koong[i]=koong[i-1]+koong[i-2]+koong[i-3]+koong[i-4];
	}
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%lld\n", koong[n]);
	}
	return 0;
}