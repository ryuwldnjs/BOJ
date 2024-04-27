#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge{
	int a,b,cost;
	bool operator<(const Edge &other)const{
		return cost > other.cost;
	}
};
int n,m,x,y;
vector<Edge> edge;
vector<int> parent(100000+5, -1);

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
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		edge.push_back({a,b,c});
	}
	cin>>x>>y;
	
	sort(edge.begin(), edge.end());
	
	for(int i=0;i<edge.size();i++){
		int a = edge[i].a;
		int b = edge[i].b;
		int cost = edge[i].cost;
		if(merge(a,b) && find(x) == find(y)){
			cout<<cost;
			return 0;
		}
	}
	return 0;
}