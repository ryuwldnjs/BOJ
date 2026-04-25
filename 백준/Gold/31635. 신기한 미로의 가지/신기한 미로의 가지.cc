#include <iostream>
using namespace std;
int n;
bool visited[105];
int parent[105];
int cnt=1;
int position = 1; 
int solve(int now){
	visited[now] = true;
	if(cnt == n) return 1;
	while(true){
		cout<<"maze"<<endl;
		int next;cin>>next;
//		position = next;
		
		if(!visited[next]){
			parent[next] = now;
			cnt++;
			if(cnt == n) return 1;
			if(solve(next)) return 1;
		}
		else{
			if(cnt == n) return 1;
			if(next == parent[now]) break;
			cout<<"gaji "<<now<<endl;
			cin>>position;
			cout<<"gaji "<<parent[now]<<endl;
			cin>>position;//버림용
			break;
		}
		
	}
//	if(position != now) {
//		cout<<"gaji "<<now<<endl;
//		cin>>position;
//	};
	return 0;
}
int main(){
	cin>>n;
	solve(1);	
	cout<<"answer"<<endl;
	for(int i=1;i<=n;i++){
		if(parent[i]) cout<<i<<' '<<parent[i]<<endl;
	}
	return 0;
}