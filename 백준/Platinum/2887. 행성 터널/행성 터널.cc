#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;
struct Edge{//간선 구조체 
	int u,v, cost;
};
bool comp(const Edge e1, const Edge e2){//sort매개변수로 넘겨줄 comp함수 
	return e1.cost < e2.cost;
}

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
//유니온파인드 


vector<Edge> e;
pair<int,int> pos_x[100000+5];
pair<int,int> pos_y[100000+5];
pair<int,int> pos_z[100000+5];
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, x,y,z,cnt=0;
	int result=0;

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>y>>z;
		
		pos_x[i] = {x, i};
		pos_y[i] = {y, i};
		pos_z[i] = {z, i};
		parent[i] = -1;
	}
	sort(pos_x, pos_x+n);
	sort(pos_y, pos_y+n);
	sort(pos_z, pos_z+n);
	for(int i=0;i<n-1;i++){
		e.push_back({pos_x[i].second, pos_x[i+1].second, pos_x[i+1].first-pos_x[i].first});
		e.push_back({pos_y[i].second, pos_y[i+1].second, pos_y[i+1].first-pos_y[i].first});
		e.push_back({pos_z[i].second, pos_z[i+1].second, pos_z[i+1].first-pos_z[i].first});
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