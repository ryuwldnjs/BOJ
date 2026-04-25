#include <stdio.h>
#include <algorithm>
using namespace std;
int m,x,y,arr[4]={0,1,0,0}; //편의상 인덱스1부터 시작 
int main(){
	scanf("%d", &m);
	for(int i=0;i<m;i++){
		scanf("%d %d", &x, &y);
		swap(arr[x], arr[y]);
		
	}
	for(int i=1;i<=3;i++){
		if(arr[i]) printf("%d",i);
	}
	return 0;
}