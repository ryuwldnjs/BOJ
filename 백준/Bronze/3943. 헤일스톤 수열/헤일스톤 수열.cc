#include <stdio.h>
int t,n;
int main(){
	scanf("%d", &t);
	for(int i=0;i<t;i++){
		scanf("%d", &n);
		int max=n;
		while(n!=1){
			if(n%2==0) n/=2;
			else n = 3*n+1;
			if(n>max) max=n;
		}
		printf("%d\n", max);
	}
	return 0;
}