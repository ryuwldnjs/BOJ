#include <stdio.h>
int t,n;
char str[25];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %s", &n, str);
		for(int i=0;str[i];i++){
			for(int j=0;j<n;j++){
				printf("%c",str[i]);
			}
		}
		printf("\n");
	}
	return 0;
}