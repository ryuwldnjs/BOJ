#include <iostream>
#include <vector>
#include <cmath>
#define MAX 100000000
using namespace std;

bool era[MAX+5];
vector<int> prime;
vector<pair<int, int> > factors;
long long n, answer=1;
int main(){
	cin>>n;
	if(n==1){
		cout<<1;
		return 0;
	}
	/*
	for(long long i=2;i<=MAX;i++) era[i] = true;
	
	for(long long i=2;i<=MAX+1;i++){
		if(era[i]) prime.push_back(i);
		for(long long j=2*i;j<=MAX+1;j+=i){
			era[j] = false;
		}
	}
	//여기까지 소수 찾기 - 에라토스 테네스 
	
	for(int i=0;i<prime.size();i++){
		if(n==1) break;
		int cnt=0;
		while(n%prime[i]==0){
			n /= prime[i];
			cnt++;
		}	
		if(cnt) factors.push_back({prime[i], cnt});
	}
	//여기까지 소인수 분해하기
	*/
	
	
	
	//오일러 phi 함수
	// f(a^m) = a^(m-1)(a-1) 
	answer = n;
	for(long long i = 2;i*i<=n;i++){
		if(n%i==0){
			while(n%i==0){
				n /= i;
			}
			answer = answer/i*(i-1);// answer*(1-1/i)와 동치 
		}
	}
	if(n!=1) answer = answer/n*(n-1); 
	
	/*
	for(int i=0;i<factors.size();i++){
		answer *= pow(factors[i].first, factors[i].second - 1) * (factors[i].first - 1);
	}*/
	
	cout<<answer;
	return 0;
}