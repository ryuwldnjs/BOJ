#include <iostream>

using namespace std;
long long n, ans;
int main(){
	//7n-21
	cin>>n;
	if(n <=1){
		cout<<1;
		return 0;
	} 
	else if(n <= 3){
		cout<<2;
		return 0;
	} 
	else if(n <= 6){
		cout<<3;
		return 0;
	} 
	else if(n <= 10){
		cout<<4;
		return 0;
	} 
	else if(n <= 15){
		cout<<5;
		return 0;
	} 
	else if(n <= 21){
		cout<<6;
		return 0;
	} 
	ans = (n + 21) / 7;
	if((n+21) % 7) ans++;
	cout<<ans;
	return 0;
}