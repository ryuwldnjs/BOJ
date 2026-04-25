#include <stdio.h>
int t,a,b; 
int main(){
	scanf("%d", &t);
	
	while(t--){
		scanf("%d %d", &a, &b);
		int tmp=a;
		b= b%4+4;
		for(int i=0;i<b-1;i++){
			tmp = (tmp*a)%10;
		}
		if(tmp==0) tmp=10;
		printf("%d\n", tmp);
	}
	
	return 0;
}