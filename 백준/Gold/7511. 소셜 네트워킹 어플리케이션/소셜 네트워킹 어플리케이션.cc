#include <iostream>
#include <vector>
using namespace std;
int t,n,k,m,a,b;
vector<int> parent;
int find(int x){
	if(parent[x] < 0) return x;
	return parent[x] = find(parent[x]);
}

int merge(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return 0;
	parent[b] = a;
	return 1;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>t;
	for(int tc=1;tc<=t;tc++){
		cin>>n>>k;
		parent = vector<int>(n, -1);
		while(k--){
			cin>>a>>b;
			merge(a,b);
		}
		cin>>m; cout<<"Scenario "<<tc<<":\n";
		while(m--){
			cin>>a>>b;
			if(find(a) == find(b)) cout<<"1\n";
			else cout<<"0\n";
		}
		
		cout<<'\n';
	}
	return 0;
}