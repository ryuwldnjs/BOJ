#include <iostream>
#include <vector>
using namespace std;

vector<int> parent(100000+5, -1), time(100000+5);
int n,m,a,b;
int cnt;
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
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		merge(a,b);
	}
	for(int i=0;i<n;i++){
		cin>>time[i];
		if(!i) continue;
		
		if(find(time[i-1]) != find(time[i])) cnt++;
	}
	cout<<cnt;
	return 0;
}