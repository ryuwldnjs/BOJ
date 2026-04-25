#include <iostream>
#include <vector> 
using namespace std;
int era[4000000+5];
vector<int> prime;
int n, cnt;
int main(){
	cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
	fill(era, era+n+5, 1);
	
	//에라이! 토스테네스 
	for(int i=2;i<=n;i++){
		if(era[i]) prime.push_back(i);
		for(int j =2*i;j<=n;j+=i){
			era[j] = 0;
		}
	}
	int l=0, r=0;
	int sum = prime[0];
	
	//투 포인터 
	while(l<=r && r<prime.size()){
		if(sum > n){
			sum -= prime[l];
			l++;
		}
		else if(sum < n){
			r++;
			sum += prime[r];
		}
		else {//답을 찾을 경우 
			cnt++;
			r++;
			sum += prime[r];
		}
	}
	cout<<cnt;
	return 0;
}