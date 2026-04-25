#include <stdio.h>
int n,k,cnt;
bool era[1005];
int main(){
	scanf("%d %d", &n, &k);
	
	for(int i=2;i<=n;i++)
		era[i]=true;
		
	
	for(int i=2;i<=n;i++){
		if(era[i]){
		//	cnt++;
			for(int j=i;j<=n;j+=i){
				if(era[j]){
				era[j]=false;
				cnt++;
				}
			//	printf("%d,%d\n", j,cnt);
				if(cnt==k){
					printf("%d", j);
					return 0;
				}
			}
		}
	}
	return 0;
}