#include <iostream>
#include <vector>
using namespace std;


vector<int> prime; //소수 목록 
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n;
	cin>>n;
	bool era[n+1];//에라토스테네스의 체 
	fill(era+2, era+n+1, true);
	 
	for(long long i=2;i<=n;i++){
		if(era[i]) prime.push_back(i); 
        else continue;
		for(long long j=i*i;j<=n; j+=i*2){
			era[j] = false;
		}
	}
	//체 완성 
	
	
	for(int i=0; n>1; i++){
		while(n % prime[i] == 0){
			cout<<prime[i]<<'\n';
			n /= prime[i];
		}
	}
	return 0;
}