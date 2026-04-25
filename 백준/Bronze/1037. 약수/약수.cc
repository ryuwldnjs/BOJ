#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vec;
int a,b;
int main(){
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b;
		vec.push_back(b);
	}
	sort(vec.begin(), vec.end());
	int answer = vec.front() * vec.back();
	cout<<answer;
	return 0;
}