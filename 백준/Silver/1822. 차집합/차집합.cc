#include <iostream>
#include <set>
using namespace std;
set<int> s;
int n,m,x;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>x;
		s.insert(x);
	}
	for(int i=0;i<m;i++){
		cin>>x;
		auto it = s.find(x);
		if(it != s.end()){
			s.erase(it);
		}
	}
	cout<<s.size()<<'\n';
	for(auto it = s.begin(); it!=s.end(); it++){
		cout<<*it<<' ';
	}
	return 0;
}