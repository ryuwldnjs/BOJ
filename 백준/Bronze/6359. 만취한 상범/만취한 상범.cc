#include <stdio.h>
int t,n;
int main(){
	scanf("%d", &t);
	
	while(t--){
		scanf("%d", &n);
		int i;
		for(i=1;i*i<=n;i++);
		printf("%d\n",i-1);
	}
	return 0;
}