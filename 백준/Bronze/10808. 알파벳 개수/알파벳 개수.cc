#include <stdio.h>
char str[105];
int cnt[30];
int main(){
	scanf("%s", &str);
	for(int i=0;str[i];i++){
		int alpha = str[i] - 'a';
		cnt[alpha]++;
	}
	for(int i=0;i<26;i++){
		printf("%d ",cnt[i]);
	}
	return 0;
}