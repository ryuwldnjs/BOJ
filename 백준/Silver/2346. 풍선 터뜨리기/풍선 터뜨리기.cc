#include <iostream>
#include <deque>
using namespace std;
struct Info{
	int idx, val;
};
deque<Info> dq;
int n,x;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		dq.push_back({i, x});
	}
	
	while(!dq.empty()){
		Info now = dq.front();
		dq.pop_front();
		cout<<now.idx<<' ';
		
		while(now.val > 1 && now.val--){
			dq.push_back(dq.front());
			dq.pop_front();
		}
		
		while(now.val < 0 && now.val++){
			dq.push_front(dq.back());
			dq.pop_back();			
		}
	}
	return 0;
}