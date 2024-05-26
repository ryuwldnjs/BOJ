#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,cnt_a, cnt_b;
vector<int> a,b; 
int main(){
	cin>>n;
	a.resize(n); 
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	b = a;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(a[j] > a[j+1]){
				swap(a[j], a[j+1]);
				cnt_a++;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(b[j] < b[j+1]){
				swap(b[j], b[j+1]);
				cnt_b++;
			}
		}
	}
//	cout<<cnt_a<<' '<<cnt_b;
	cout<<min(cnt_a, cnt_b + 1);
	return 0;
}