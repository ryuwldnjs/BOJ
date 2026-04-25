#include <stdio.h>
int cnt,arr[25],n,s;
void solve(int idx, int sum){
	if(idx>=n){
		if(sum==s) cnt++;
		return;
	}
	
	solve(idx+1, sum); //idx택 x 
	solve(idx+1, sum+arr[idx]); //idx 택할때 
}
int main(){
	scanf("%d %d", &n, &s);
	for(int i=0;i<n;i++) {
		scanf("%d", &arr[i]);
	}
	
	solve(0,0);
	if(s==0) cnt--; //s==0일때, 공집합도 카운팅 되므로 
	printf("%d", cnt);
	return 0;
}

 
/*int n,s,num,psum[25]={0},cnt;
int main(){
	scanf("%d %d", &n, &s);
	for(int i=1;i<=n;i++) {
		scanf("%d", &num);
		psum[i] = psum[i-1]+num;
	}
	
	for(int i=0;i<=n;i++) printf("%d\n", psum[i]);
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			if (psum[i] - psum[j] == s) printf("[%d,%d]\n", i,j);
		}
	}
	printf("%d", cnt);
	return 0;
}*/