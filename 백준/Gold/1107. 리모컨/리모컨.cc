#include<iostream>
#include <vector>
#include <queue>
#define INF 1234567890
using namespace std;

vector<bool> ban(10, false); //고장난 버튼들 
int n,m,k,MIN=INF;
int sz(int n){
	int size=0;
	while(n){
		n/=10;
		size++;
	}
	return size;
}
bool able(int n){
	while(n){
		if(ban[n%10]) return false;
		n/=10;
	}
	return true;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>k;
		ban[k] = true;
	}
	
	if(!ban[0]) MIN = 1 + n; //0번으로 간 후 조작 
	
	MIN = min(MIN, abs(100-n)); //100번에서 시작
	 
	for(int i=1;i<=1000000; i++){
		if(able(i)) MIN = min(MIN, sz(i) + abs(n-i));
	}
	
	
	cout<<MIN;
	return 0;
}