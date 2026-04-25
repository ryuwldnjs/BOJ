#include <stdio.h>
#include <algorithm>
int n,num;
bool retake[105];
int main(){
	scanf("%d", &n);
	
//	memset(retake, true, sizeof(int)*105);
	for(int i=1;i<=n;i++){
		int j=1;
		for(j=1;j<=10;j++){
		//	printf("sada");
			scanf("%d", &num);
			if(num != ((j-1)%5+1)){
				retake[i]=true;
			}
		}
		
	}
	
	for(int i=1;i<=n;i++){
		if(!retake[i]) printf("%d\n", i);
	}
	return 0;
}