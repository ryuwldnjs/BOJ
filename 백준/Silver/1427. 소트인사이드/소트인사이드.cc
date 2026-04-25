#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;

int n,i,arr[11];
int main(){
	cin>>n;
	while(n){
		vec.push_back(n%10);
		n/=10;
	}
	sort(vec.begin(), vec.end());
	
	for(int i=vec.size()-1;i>=0;i--){
		cout<<vec[i];
	}
	return 0;
}