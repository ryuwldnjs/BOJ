#include <stdio.h>
int n,arr[105],v,cnt;
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	scanf("%d", &v);
	for(int i=0;i<n;i++){
		if(arr[i] == v) cnt++;
	}
	
	printf("%d", cnt);
	return 0;
}