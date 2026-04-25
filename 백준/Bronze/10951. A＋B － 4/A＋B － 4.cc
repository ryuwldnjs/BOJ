#include <stdio.h>
int a,b,t;
int main(){
	while(scanf("%d %d", &a, &b) != EOF){
		printf("%d\n", a+b);
	}
	return 0;
}