#include <stdio.h>
int a,b;
int main(){
	scanf("%d %d", &a, &b);
	while(a!=0 && b!=0){
		printf("%d\n", a+b);
		scanf("%d %d", &a, &b);
	}
	return 0;
}