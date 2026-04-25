#include <stdio.h>
#include <algorithm>
using namespace std;
int a[55], b[55];
int n,sum;
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d", &b[i]);
	}
	sort(a,a+n);
	sort(b,b+n);
	for(int i=0;i<n;i++){
		sum += a[i]*b[n-i-1];
	}
	printf("%d", sum);
	return 0;
}