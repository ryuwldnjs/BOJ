#include <iostream>
using namespace std;
int n,m,a,b;
int parent[500000+5];

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
	cin>>n>>m;
	fill(parent, parent+n, -1);
	
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		if(merge(a,b) == 0) {
			cout<<i;
			return 0;
		}
	}
	cout<<0;
	return 0;
}