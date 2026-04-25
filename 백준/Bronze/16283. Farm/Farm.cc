#include <stdio.h>
int a,b,n,w;
int cnt,ans_a, ans_b;
int main(){
	scanf("%d %d %d %d", &a, &b, &n, &w);
	// x+y = n ...1번식
    // ax+by = w ...2번식
	for(int i=1;i<n;i++){
		int tmp = (a-b)*i+b*n;
		if(tmp==w){
			ans_a=i;
			ans_b=n-i;
			cnt++;
		}
		
	}
	
	if(cnt==1) printf("%d %d", ans_a, ans_b);
	else printf("-1");
	return 0;
}