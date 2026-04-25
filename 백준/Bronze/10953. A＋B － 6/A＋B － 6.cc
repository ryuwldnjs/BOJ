#include <stdio.h>
int a,b,t;
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d,%d", &a, &b);
		printf("%d\n", a+b);
	}
	return 0;
}