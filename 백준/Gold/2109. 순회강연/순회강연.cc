#include <iostream>
#include <queue>
using namespace std;
vector<int> lectures[10000+5];
priority_queue<int> pq;
int n, ans;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int p,d; cin>>p>>d;
		lectures[d].push_back(p);
	}
	for(int i=10000;i>=1;i--){
		for(auto payment: lectures[i]){
			pq.push(payment);
		}
		if(pq.empty()) continue;	
		ans += pq.top();
		pq.pop();
	}
	
	cout<<ans;
	return 0;
}