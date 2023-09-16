#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int n,k;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++) q.push(i);
	cout<<'<';
	for(int cnt=1;!q.empty();cnt++){
		int now = q.front();
		q.pop();
		if(cnt%k != 0) {
			q.push(now);
		}
		else{
			cout<<now;
			if(q.empty()) cout<<'>';
			else cout<<", ";
		}	
	}
	return 0;
}