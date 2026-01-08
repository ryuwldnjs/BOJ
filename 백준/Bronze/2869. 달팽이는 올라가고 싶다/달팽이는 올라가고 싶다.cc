#include <stdio.h>
int a,b,v,height,cnt;
int main(){
	scanf("%d %d %d", &a, &b, &v);
	
	v-=a;
	cnt++;
	
	cnt+= (v+a-b-1)/(a-b);
	printf("%d", cnt);
	return 0;
}