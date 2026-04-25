#include <iostream>
#include <vector> 
#include <algorithm>
#include <cmath>
using namespace std;
struct Edge{//간선 구조체 
	int u,v;
	double cost;
};
bool comp(const Edge e1, const Edge e2){//연산자 오버로딩 
	return e1.cost < e2.cost;
}

int parent[100+5]; 
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



double dist(double x1, double y1, double x2, double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

vector<Edge> e;
pair<int,int> vertex[100+5];
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, cnt=0;
	double x,y, result=0.0;

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		vertex[i].first = x;
		vertex[i].second = y;
		parent[i] = -1;
		for(int j=0;j<i;j++){
			e.push_back({j, i, dist(x, y, vertex[j].first, vertex[j].second)});
		}
	}
	sort(e.begin(), e.end(), comp);
	
	
	for(int i=0;i<e.size();i++){
		if(merge(e[i].u, e[i].v)){//유니온 성공시 
			result += e[i].cost;
			cnt++;
			if(cnt == n-1) break;
		}
	}
	cout<<result;
	return 0;
}