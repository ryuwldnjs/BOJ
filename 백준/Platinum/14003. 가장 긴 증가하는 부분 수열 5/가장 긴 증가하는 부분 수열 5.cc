#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> A(1000000+5), lis, corr(1000000+5), answer;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>A[i];
		int idx = lower_bound(lis.begin(), lis.end(), A[i]) - lis.begin();
		if(idx == lis.size()) lis.push_back(A[i]);
		else lis[idx] = A[i];
		corr[i] = idx;
	}
	// A[]   = 1 3 6 9 4
	// lis[] = 1 3 4 9
	//corr[] = 0 1 2 3 2 
	//corr를 역순으로 돌면서 큰 숫자부터 작은숫자로 한번씩 회수 
	int target = lis.size() - 1; //LIS 길이
	for(int i=n-1;i>=0;i--){
		if(target == corr[i]){
			target--;
			answer.push_back(A[i]);
		}
	}
	
	cout<<lis.size()<<'\n';
	for(auto it = answer.rbegin(); it != answer.rend(); it++){
		cout<<*it<<' ';
	}
	return 0;
}