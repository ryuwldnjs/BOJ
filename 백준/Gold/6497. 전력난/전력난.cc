#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Info{
	int a,b,cost;
	
	bool operator<(const Info other)const{
		return cost < other.cost; 
	}
};

int n,m,a,b,c;
vector<Info> edge;
vector<int> parent;

int answer;
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
	while(true){
		cin>>m>>n;
		answer = 0;
		parent = vector<int>(m, -1);
		edge = vector<Info>();
		if(m==0 && n==0) return 0;
		
		for(int i=0;i<n;i++){
			cin>>a>>b>>c;
			edge.push_back({a,b,c});
			answer += c;
		}
		sort(edge.begin(), edge.end());
		for(int i=0;i<n;i++){
			if(merge(edge[i].a, edge[i].b)){
				answer-= edge[i].cost;
			}
		}
		cout<<answer<<'\n';
	}
	return 0;
}