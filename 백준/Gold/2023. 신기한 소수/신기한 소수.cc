#include <iostream>
using namespace std;
	int n;
int isprime(int k){
	for(int i=2;i*i<=k;i++){
		if(k%i==0) return 0;
	}
	return 1;
}
void backtrack(int level, int k){
	if(level==n){
		cout<<k<<'\n';
		return;
	}
	
	for(int i=1;i<10;i++){
		if(i==1&&level==0) continue;
		if(isprime(10*k+i))
			backtrack(level+1, 10*k+i);
	}
	
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin>>n;
	
	backtrack(0, 0);
	return 0;
}