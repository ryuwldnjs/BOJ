#include <iostream>
using namespace std;
int MAX = -1234567890;
int MIN = 1234567890;
int n, arr[12], oper[4];

//네가지 연산 
int op(int val, int idx, int i){
	if(i==0) val += arr[idx+1];
	if(i==1) val -= arr[idx+1];
	if(i==2) val *= arr[idx+1];
	if(i==3) val /= arr[idx+1];
	return val;
}

//백트래킹 
void solve(int idx, int cal){
	//기저사례 : 모든 연산을 사용했을 경우 
	if(idx==n-1){
		MAX = max(MAX, cal); 
		MIN = min(MIN, cal); 
		return;
	}
	
	for(int i=0;i<4;i++){
		if(oper[i]){
			if(i==3 && arr[idx+1]==0) continue;
			
			oper[i]--;
			solve(idx+1, op(cal, idx, i));
			oper[i]++;
		}
	}
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<4;i++) cin>>oper[i];//연산자 개수 
	
	
	//BackTreacking
	solve(0, arr[0]);
	
	cout<<MAX<<'\n'<<MIN;
	return 0;
}