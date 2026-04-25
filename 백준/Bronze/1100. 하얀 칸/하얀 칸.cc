#include <stdio.h>
int cnt;
char horse;
int main(){
	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++){
			scanf(" %c", &horse);
			if(horse =='F' && (i+j)%2==0) cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}