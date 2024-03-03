#include <iostream>
#include <vector> 
using namespace std;
vector<int> answer;
int n,x;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		auto target = lower_bound(answer.begin(), answer.end(), x);
		if(target == answer.end()) answer.push_back(x);
		else *target = x; 
	}
	cout<<answer.size();
	return 0;
}