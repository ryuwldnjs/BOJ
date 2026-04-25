#include <stdio.h>
char str[1000000+5];
int cnt;
int main(){
	while(scanf("%s",str)!=EOF) cnt++;
	printf("%d",cnt);
	return 0;
}