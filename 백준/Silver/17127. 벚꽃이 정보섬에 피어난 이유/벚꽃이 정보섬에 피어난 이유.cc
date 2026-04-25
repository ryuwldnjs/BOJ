#include <stdio.h>
//완전탐색 복잡도 ==  최대 5^10 
int n,a[12];
int product=1;
int sum,max;
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	for(int i=0;i<4;i++){
		product =1;
		sum =0;
		for(int j=0;j<n;j++){
			if(j>=i && j<n-3+i)
				product *= a[j];
			else
				sum+= a[j];
		}
	//	printf("sum=%d, product=%d.\n", sum,product);
		sum+=product;
		if(sum>max) max = sum;
	}
	
	printf("%d", max);
	return 0;
}