#include <iostream>
#include <vector>
using namespace std;
vector<int> parent(300000+5, -1);
int n,a,b;
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
	cin>>n;
	for(int i=0;i<n-2;i++){
		cin>>a>>b;
		merge(a,b);
	}
	for(int i=2;i<=n;i++){
		if(merge(1, i)){
			cout<<1<<' '<<i;
			return 0;
		}
	}
	return 0;
}