#include <iostream>
#include <vector>
#include <queue> 
using namespace std;
int t,n,m,a,b;
vector<int> plane;
queue<int> q;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>t;
	
	while(t--){
		cin>>n>>m;
		
		
		plane.resize(n+1);
		for(int i=0;i<m;i++){
			cin>>a>>b;
		//	plane[a].push_back(b);
		//	plane[b].push_back(a); // 쌍방향 연결 
			
			
		}
		
		cout<<n-1<<"\n";
		
		
	}
	return 0;
} 