#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct Edge{
	int a,b;
	double cost;
	bool operator<(const Edge other)const{
		return cost < other.cost;
	}
};

int n,m,x[1005], y[1005];
int connected;
vector<int> parent(1005, -1);
vector<Edge> edge;
double answer;

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
	
	connected++;
	return 1;
}
double dist(ll x1, ll y1, ll x2, ll y2){
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=0;i<m;i++){
		int a,b; cin>>a>>b;
		merge(a,b);
		
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			double cost = dist(x[i], y[i], x[j], y[j]);
			edge.push_back({i,j,cost});
		}
	}
	sort(edge.begin(), edge.end());
	for(int i=0;i<edge.size();i++){
		int a = edge[i].a;
		int b = edge[i].b;
		double cost = edge[i].cost;
		if(merge(a,b)){
			answer += cost;
			if(connected == n-1) break;
		}
	}
	printf("%.2lf", answer);
	return 0;
	
}