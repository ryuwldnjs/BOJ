#include <stdio.h>
int n,dir,a,b;
int ans_dir;
long long ans=1;
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d %d %d", &a, &b, &dir);
		ans=ans*b/a;
		if(dir==1) ans_dir = (ans_dir+1)%2;
	}
	printf("%d %lld", ans_dir,ans);
	return 0;
}