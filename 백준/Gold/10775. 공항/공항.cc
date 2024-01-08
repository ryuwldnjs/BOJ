#include <iostream>
using namespace std;

int g,p,x;
int parent[100000+5];
int find(int x){
	if(parent[x] < 0) return x;
	
	return parent[x] = find(parent[x]);
}
int merge(int a,int b){
	a = find(a);
	b = find(b);
	
	parent[b] = a;
	return 1;
}
int main(){
	cin>>g>>p;
	fill(parent, parent + g+1, -1);
	for(int i=0;i<p;i++){
		cin>>x;
		int parent_x = find(x);
		if(parent_x == 0){
			cout<<i;
			return 0;
		}else{
			merge(parent_x-1, parent_x);
		}
	}
	cout<<p;
	return 0;
}