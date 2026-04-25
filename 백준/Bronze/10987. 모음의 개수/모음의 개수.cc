#include <stdio.h>
char str[105], aeiou[6]="aeiou";
int cnt;
int main(){
	scanf("%s", str);
	
	for(int i=0;str[i];i++){
		for(int j=0;j<5;j++){
			if(str[i]==aeiou[j]) cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}