#include <iostream>
#include <algorithm>
using namespace std;
struct Edge{//간선 구조체 
	int u,v,cost;
};
bool comp(const Edge e1, const Edge e2){//연산자 오버로딩 
	return e1.cost < e2.cost;
}


int parent[1000+5]; 
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
//유니온파인드 


Edge e[100000+5];
int result, cnt;
int main(){
	int n,m;
	int a,b,c;
	
	cin>>n>>m;
	for(int i=0;i<n+1;i++) parent[i] = -1;
	
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		e[i] = {a,b,c};
	}
	sort(e, e+m, comp);
	
	
	for(int i=0;i<m;i++){
		if(merge(e[i].u, e[i].v)){//유니온 성공시 
			result += e[i].cost;
			cnt++;
			if(cnt == n-1) break;
		}
	}
	cout<<result;
	return 0;
}