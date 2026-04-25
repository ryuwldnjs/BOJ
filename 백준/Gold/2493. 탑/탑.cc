#include <iostream>
#include <stack>
#define INF 1234567890
using namespace std;

stack<pair<int, int> > s;//높이와 인덱스 
int n,arr[500000+5];
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>arr[i];
	
	s.push({INF, 0});//0번 인덱스에 커다란 벽을 세움 
	
	
	for(int i=1;i<=n;i++){
		while(s.top().first < arr[i])
			s.pop();
		
		cout<<s.top().second<<' ';
		
		s.push({arr[i], i});		
	}
	return 0;
}