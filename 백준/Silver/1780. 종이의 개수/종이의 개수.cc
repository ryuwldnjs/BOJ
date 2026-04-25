#include <stdio.h>
int n, map[2222][2222], cnt[3];
bool check(int x1, int y1, int x2, int y2){
	int paper = map[x1][y1];//첫번째 블럭 색깔 
	for(int i=y1;i<=y2;i++){
		for(int j=x1;j<=x2;j++){
		//	printf("(%d, %d) ", i,j);
			if(map[j][i] != paper) return false; //다른 색 찾을때 
		}
	}
	return true;
}

void conquer(int x1, int y1, int x2, int y2){
//	printf("dsds ");
//	printf("(%d,%d,%d,%d = %d)\n", x1,y1,x2,y2,map[x1][y1]);
	if(check(x1,y1,x2,y2)==true){//전부 같은색일때 카운팅하고 스탑 
		cnt[map[x1][y1]+1]++;

		return;
	}
	int gap = (x2-x1+1)/3;
	for(int i=0;i<3;i++){ //구간 9개로 나누기 
		for(int j=0;j<3;j++){
			conquer(j*gap+x1,i*gap+y1,j*gap+x1+gap-1,i*gap+y1+gap-1);
		}
	}	
}
int main(){
	scanf("%d", &n);
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d", &map[j][i]);
		}
	}
	conquer(1,1,n,n);
	
	printf("%d\n%d\n%d", cnt[0], cnt[1], cnt[2]);
	return 0;
}