#include <stdio.h>
#include <stdlib.h>
char a[8], b[8];
int min, max;
int main(){
	scanf("%s %s", a, b);
	
	for(int i=0;a[i];i++)
		if(a[i]=='6') a[i]='5';
	for(int i=0;b[i];i++)
		if(b[i]=='6') b[i]='5';
	min = atoi(a) + atoi(b);
	
	for(int i=0;a[i];i++)
		if(a[i]=='5') a[i]='6';
	for(int i=0;b[i];i++)
		if(b[i]=='5') b[i]='6';
	max = atoi(a) + atoi(b);
	
	printf("%d %d", min,max);
	return 0;
}