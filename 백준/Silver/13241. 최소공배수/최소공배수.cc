#include <iostream>
using namespace std;
using ll=long long;
ll a,b; 
ll gcd(ll x, ll y){
	if(!(x%y)) return y;
	return gcd(y, x%y);
}
int main(){
	cin>>a>>b;
	cout<< a*b / gcd(a,b);
	return 0;
} 