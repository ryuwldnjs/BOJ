#include <iostream>
#include <set>
using namespace std;
set<int> s;
int a,b,x;
int main(){
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>x;
		s.insert(x);
	}
	for(int i=0;i<b;i++){
		cin>>x;
		if(s.find(x) != s.end()) a-=2; // 값이 존재할때 
	}
	cout<<a+b;
	return 0;
}