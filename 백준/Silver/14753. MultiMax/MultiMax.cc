#include <stdio.h>
#include <algorithm>
using namespace std;
long long n,arr[10050], tmp[10], ans=-1234567890;
int main(){
	scanf("%lld", &n);
	for(int i=0;i<n;i++){
		scanf("%lld", &arr[i]);
	}
	
	sort(arr,arr+n);
	
	if(n>=6){
		tmp[0]=arr[0];
		tmp[1]=arr[1];
		tmp[2]=arr[2];
		tmp[3]=arr[n-3];
		tmp[4]=arr[n-2];
		tmp[5]=arr[n-1];
		tmp[6]=1;
	}
	else{
		for(int i=0;i<n;i++) tmp[i]=arr[i];
	}
	n = n>=6? 6 : n;
//	for(int i=0;i<7;i++) printf("%d ",tmp[i]);
	//2개일때
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			ans = max(ans, tmp[i]*tmp[j]);
		}
	}
	//3개일때 
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				ans = max(ans, tmp[i]*tmp[j]*tmp[k]);
			//	printf("[%d,%d,%d]%d\n",tmp[i],tmp[j],tmp[k], ans);
			}
		}
	}
	
	printf("%lld", ans);
	return 0;
}