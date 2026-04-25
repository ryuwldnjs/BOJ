#include <stdio.h>
int n,map[135][135];
int cnt[2]; //흰색, 파랑색 
bool check(int x1,int y1, int x2, int y2){ //같은 색인지체크 
	int color = map[x1][y1];//첫번째 블럭 색깔 
	for(int i=y1;i<=y2;i++){
		for(int j=x1;j<=x2;j++){
			if(map[j][i] != color) return false; //다른 색 찾을때 
		}
	}
	return true;
}

void conquer(int x1, int y1, int x2, int y2) {
	if(check(x1,y1,x2,y2)==true){//전부 같은색일때 카운팅하고 스탑 
		cnt[map[x1][y1]]++;
		return;
	}
	
	//4등분 하기 
	conquer(x1, y1, (x1+x2)/2, (y1+y2)/2); //제 2분면 
	conquer((x1+x2)/2+1, y1, x2, (y1+y2)/2); //제 1분면 
	conquer(x1, (y1+y2)/2+1, (x1+x2)/2, y2); //제 3분면 
	conquer((x1+x2)/2+1, (y1+y2)/2+1, x2, y2);//제 4분면 
}
int main(){
	scanf("%d", &n);
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d", &map[i][j]);
		}
	}
	
	conquer(1,1,n,n);
	printf("%d\n%d",cnt[0], cnt[1]); 
	return 0;
}