#include <iostream>
using namespace std;
int n,m,num;
int parent[200+5];
int village[1000+5];

int find(int n){
	if(parent[n] == n) return n;
	
	return parent[n] = find(parent[n]);
}
void merge(int a,int b){
	a = find(a);
	b = find(b);
	
	if(a==b) return;
	parent[a] = b;
}
int main(){
	cin>>n>>m;
	
	for(int i=1;i<=n;i++) parent[i]=i;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>num;
			if(num) merge(i,j);
		}
	}
	for(int i=0;i<m;i++){
		cin>>village[i];
	}
	int tmp= find(village[0]);
	for(int i=1;i<m;i++){
		if(tmp!=find(village[i])){
			cout<<"NO";
			return 0;
		}
		
	}
	cout<<"YES";
	return 0;
}