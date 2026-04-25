#include <stdio.h>
int n; 
int main(){
	scanf("%d", &n);
	
	for(int i=n;i>=1;i--){
		for(int j=0;j<i;j++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}