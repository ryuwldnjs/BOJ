#include <bits/stdc++.h>
using namespace std;

struct Edge{
	int a,b,cost;
	
	//내림차순 정렬 
	bool operator<(const Edge other)const{
		return cost > other.cost;
	}
};
vector<int> parent(100000+5, -1);
vector<Edge> edge;
int n,m,s,e;


int find(int x){
	if(parent[x] < 0) return x;
	return parent[x] = find(parent[x]);
}

int merge(int a, int b){
	a = find(a);
	b = find(b);
	
	if(a == b) return 0;
	parent[a] += parent[b];
	parent[b] = a;
	return 1;
}

int main(){
	cin>>n>>m;
	cin>>s>>e;
	for(int i=0;i<m;i++){
		int a,b,c; 
		cin>>a>>b>>c;
		edge.push_back({a,b,c});
	}
	sort(edge.begin(), edge.end());
	for(int i=0;i<edge.size();i++){
		int a = edge[i].a;
		int b = edge[i].b;
		int cost = edge[i].cost;
		//s - > e경로가 최초로 생길때 
		if(merge(a,b) && find(s) == find(e)){
			cout<<cost;
			return 0;
		}
	} 
	cout<<0; 
	return 0;
}