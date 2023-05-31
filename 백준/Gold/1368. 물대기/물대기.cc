#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct edge{
	int a,b,cost;
	bool operator <(const edge& e)const{
		return cost < e.cost; 
	}
};

vector<edge> vec;
int parent[305], n, cost,answer,connected;

int find(int a){
	if(parent[a] < 0) return a;
	return parent[a] = find(parent[a]);
}

bool merge(int a, int b){
	a = find(a);
	b = find(b);
	
	if(a == b) return false;
	parent[b] = a;
	return true;
}

int main(){
	cin>>n;
	fill(parent, parent + n + 1, -1);
	for(int i=0;i<n;i++){
		cin>>cost;
		vec.push_back({i, n, cost});
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>cost;
			if(i >= j) continue;
			vec.push_back({i, j, cost});
		}
	}
	
	sort(vec.begin(), vec.end());
	
	for(int i=0;i<vec.size();i++){
		int a = vec[i].a;
		int b = vec[i].b;
		int cost = vec[i].cost;
		
		if(merge(a, b)){
			answer += cost;
			if(++connected == n){
				cout<<answer;
				return 0;
			}
		}
	}
	return 0;
}