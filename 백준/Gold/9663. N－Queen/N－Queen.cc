#include <iostream>
#include <algorithm>
using namespace std;
int n;
int save_x[17], save_y[17];
int backtrack(int x, int y){
	//가지치기 
	for(int i=0;i<y;i++){
		if(x == save_x[i]) return 0; //같은 세로줄 
		if(y == save_y[i]) return 0; //같은 가로줄 
		if(abs(x-save_x[i])  == abs(y-save_y[i])) return 0; //대각선 
	}
	
	
	if(y==n-1){//제일 아랫칸 도달할 경우 
		return 1; 
	}
	save_x[y] = x, save_y[y] = y; //위치 저장 
	int ans = 0;
	for(int i=0;i<n;i++){
		ans += backtrack(i, y+1);
	}
	
	return ans;
}
int main(){
	cin>>n;
	int ans=0;
	for(int i=0;i<n;i++){
		ans += backtrack(i,0); // 첫 수를 어디에 두는지에 따라 
	}
	cout<<ans;
	return 0;
}