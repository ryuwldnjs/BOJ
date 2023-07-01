#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n,arr[300000+5];
double sum;
int main(){
	cin>>n;
	if(!n){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr, arr+n);
	int trim = round(0.15*n);
	for(int i=trim; i<n-trim; i++){
		sum += arr[i];
	}
	cout<<round(sum/(n-2*trim));
	return 0;
}