#include <iostream>
#include <set>
using namespace std;
multiset<int> s;
int q,n,m;

int getPages(){
	if(s.empty()) return 0;
	int answer = 1;
	int now = *s.begin();
	while(true){
		int next = now * 2;
		auto it = s.lower_bound(next);
		if(it == s.end()) break;
		
		now = *it;
		answer++;
	}
	return answer;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>q;
	while(q--){
		cin>>n;
		if(n == 1){
			cin>>m;
			s.insert(m);
		}
		else if(n == 2){
			cin>>m;
			auto it = s.find(m);
			if(it != s.end()) s.erase(it);
		}
		else{
			cout<<getPages()<<'\n';
		}
	}
	return 0;
}