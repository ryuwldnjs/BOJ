#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int n,ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) q.push(i);
	
	
	while(!q.empty()){
		ans = q.front();
		q.pop(); //맨 윗장 날리기 
		
		if(!q.empty()){//맨뒤로 보내기 
			q.push(q.front());
			q.pop();
		}
	}
	
	cout<<ans;
	return 0;
}