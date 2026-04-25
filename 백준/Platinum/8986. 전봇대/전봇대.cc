#include <iostream>
#include <algorithm>
using namespace std;
long long n,arr[100000+5];
long long answer=1e18;
//간격을 x로 할때 이동거리 합 
long long f(int x){
	long long sum=0;
	for(int i=1;i<n;i++){
		sum += abs((long long)arr[i] - (long long)x*i);
	}
	return sum;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	
	long long lo=0, hi=arr[n-1];
	
	for(int i=0;i<100;i++){
		int a = (2*lo+hi)/3;
		int b = (lo+2*hi)/3;
		
		if(f(a) < f(b))
			hi = b;
		else lo = a;
	}
	
	for(int i=lo;i<=hi;i++){
		answer = min(answer, f(i));
	}
	cout<<answer;
	return 0;
}