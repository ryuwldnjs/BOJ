#include <iostream>
#include <stack>

using namespace std;
stack<int> s;
int idx=1;
int n,k, arr[100000+10];
int main(){
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
		k = arr[i];
		if(!s.empty() && k < s.top()){
			cout<<"NO";
			return 0;
		}
		if(!s.empty() && k == s.top()){
			s.pop();
			continue;
		}

		do{
			s.push(idx++);
		}while(k != s.top());
		
		if(!s.empty() && k == s.top()){
			s.pop();
		}
		
	}
	
	
	s = stack<int>();
	idx = 1;
	
	for(int i=0;i<n;i++){
		k = arr[i];

		if(!s.empty() && k == s.top()){
			s.pop();
			cout<<"-\n";
			continue;
		}

		do{
			s.push(idx++);
			cout<<"+\n";
		}while(k != s.top());
		
		if(!s.empty() && k == s.top()){
			s.pop();
			cout<<"-\n";
		}
		
	}
	
	return 0;
}