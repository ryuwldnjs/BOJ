#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> s;
int n,arr[1000000+50], cnt[1000000+50];

vector<int> answer;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		cnt[ arr[i] ]++;
	}
	
	for(int i=n-1;i>=0;i--){
		while(!s.empty() && cnt[s.top()] <= cnt[arr[i]])
			s.pop();
		if(s.empty()) answer.push_back(-1);
		else answer.push_back(s.top());
		
		s.push(arr[i]);
	}
	
	for(int i=answer.size()-1; i>=0; i--){
		cout<<answer[i]<<' ';
	}
	return 0;
}