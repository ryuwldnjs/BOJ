#include <iostream>
#include <stack>
using namespace std;
stack<pair<int,int> > s;//val,chk
long long answer;
int n;
int arr[500000+5];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		long long check = 1;
		while(!s.empty() && s.top().first <= arr[i]){
			answer += s.top().second;
			if(s.top().first == arr[i]) check += s.top().second;
			s.pop();
		}
		if(!s.empty()) answer++;
		s.push({arr[i], check});
	}
	cout<<answer;
	return 0;
}