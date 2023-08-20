#include <iostream>
#include <algorithm>
using namespace std;
struct Edge{
	int u,v,cost;
	
	bool operator < (const Edge& e)const{
		return cost < e.cost;
	}
};
Edge e[1000000+5];
//유니온파인드 
int parent[100000+5]; 
int find(int a){
	if(parent[a] < 0) return a;
	return parent[a] = find(parent[a]);
}

int merge(int a, int b){
	a = find(a);
	b = find(b);
	
	if(a==b) return 0;
	
	parent[b] = a;
	return 1;
}

int n,m, sum,cnt;
int a,b,c;
int main(){
	cin>>n>>m;
	fill(parent+1, parent+n+1, -1);
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		e[i]={a,b,c};
	}
	sort(e, e+m);
	
	for(int i=0;i<m;i++){
		if(cnt==n-2) break;
		if(merge(e[i].u, e[i].v)){
			sum += e[i].cost;
			cnt++;
		}
	}
	
	cout<<sum;
	return 0;
}