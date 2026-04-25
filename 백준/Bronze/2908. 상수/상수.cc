#include <stdio.h>
char a[4], b[4];
void reverse(char ch[]){
	for(int i=2;i>=0;i--){
		printf("%c",ch[i]);
	}
}

int main(){
	scanf("%s %s", &a, &b);
	for(int i=2;i>=0;i--){
		if(a[i]>b[i]) reverse(a);
		else if(a[i]<b[i]) reverse(b);
		if(a[i]!=b[i]) return 0;
	}
	return 0;
}