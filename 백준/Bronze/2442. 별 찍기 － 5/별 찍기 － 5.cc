#include <stdio.h>
int n;
int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n+i-1;j++){
			if(j<=n-i) printf(" ");
			else printf("*");
		}
		printf("\n");
	}
	return 0;
}