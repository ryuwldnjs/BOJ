#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,k,a;
vector<int> info,gap;
int answer;
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a;info.push_back(a);
	}
	info.push_back(0);
	sort(info.begin(), info.end());
	for(int i=1;i<info.size();i++){
		gap.push_back(info[i]-info[i-1]);
	}
	sort(gap.begin(), gap.end());
	for(int i=0;i<gap.size() - k;i++){
		answer += gap[i];
	}
	cout<<answer;
	return 0;
}