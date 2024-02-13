#include <bits/stdc++.h>
using namespace std;
long long k,n;
long long lan[1000000+5];

bool able(long long x){ //길이x로 잘랐을때, n개의 랜선을 확보할수있는가? 
	long long cnt = 0;
	for(int i=0;i<k;i++){
		cnt += lan[i] / x;
	}
	return cnt >= n;
}
int main(){
	cin>>k>>n;
	for(int i=0;i<k;i++){
		cin>>lan[i];
	}
	long long left = 1;
	long long right = 0x7FFFFFFF;
	for(int i=0;i<200;i++){
		long long mid = (left + right) / 2;
		if(able(mid))
			left = mid;
		else
			right = mid-1;
	}
	cout<<(able(right) ? right : left);
	return 0;
}