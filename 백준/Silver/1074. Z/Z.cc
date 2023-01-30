#include <iostream>

using namespace std;
int  order, answer;
int n,r,c;

bool pass(int x1, int y1, int x2, int y2){
	return x1<=c&&c<=x2 && y1<=r&&r<=y2 ? true : false;
}
void solve(int x1, int y1, int x2, int y2){
//	printf("[%d,%d||%d,%d]\n", x1,y1,x2,y2);

	if(x1 == x2 && x1 == c && y1 == r) {
		answer = order;	
		return;
	} 
	
		
	int x_mid = (x1+x2)/2;
	int y_mid = (y1+y2)/2;
	int size = (x2-x_mid) * (x2-x_mid);
	
	//목표보다 앞에 있으면 n*n블럭만큼  더하기
	//목표보다 뒤에 있으면 생략 
	if(pass(x1, y1, x_mid, y_mid)){
		solve(x1, y1, x_mid, y_mid);
	}
	else if(pass(x_mid+1, y1, x2, y_mid)){
		order += size;
		solve(x_mid+1, y1, x2, y_mid);
	}
	else if(pass(x1, y_mid+1, x_mid, y2)){
		order += 2*size;
		solve(x1, y_mid+1, x_mid, y2);
	}
	else if(pass(x_mid+1, y_mid+1, x2, y2)){
		order += 3*size;
		solve(x_mid+1, y_mid+1, x2, y2);
	}
	return;
}
int main(){
	cin>>n>>r>>c;
	n = 1<<n;
	
//	printf("%d", n);
	solve(0,0,n-1,n-1);
	
	cout<<answer;
	return 0;
} 