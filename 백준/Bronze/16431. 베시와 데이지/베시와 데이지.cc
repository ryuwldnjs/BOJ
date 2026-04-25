#include <stdio.h>
#include <algorithm>
using namespace std;
int B_x,B_y;
int D_x,D_y;
int J_x,J_y;
int B_cnt, D_cnt;
int main(){
	scanf("%d %d %d %d %d %d", &B_x, &B_y, &D_x, &D_y, &J_x, &J_y);
	
	
	B_cnt = max(abs(B_x-J_x), abs(B_y-J_y));
	D_cnt = abs(D_x-J_x)+abs(D_y-J_y);
	if(B_cnt<D_cnt) printf("bessie");
	else if(B_cnt>D_cnt) printf("daisy");
	else printf("tie");
	return 0;
}