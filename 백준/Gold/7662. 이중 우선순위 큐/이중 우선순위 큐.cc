#include <iostream>
#include <set>
using namespace std;

multiset<int> s;
char a;
int T,k,b;
int main(){
	cin>>T;
	
	while(T--){
		cin>>k;
		s = multiset<int>();
		for(int i=0;i<k;i++){
			cin>>a>>b;
		
			if(a=='I') s.insert(b);
			else if(!s.empty()){
				if(b == 1) s.erase(--s.end());
				else s.erase(s.begin());
			}
		}
		
		if(s.empty()) cout<<"EMPTY\n";
		else cout<<*(--s.end())<<' '<<*s.begin()<<'\n';
	}
	
	return 0;
}