#include <stdio.h>
int max,arr[105],n,m;

int main(){
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	
	
	for(int i=2;i<n;i++){
		for(int j=1;j<i;j++){
			for(int k=0;k<j;k++){
				int sum = arr[k]+arr[j]+arr[i];
				if(sum<=m&&sum>max){ //m을 넘지 않는 선에서 
					max = sum;
				}
			}
		}
	}
	printf("%d", max);
	return 0;
}