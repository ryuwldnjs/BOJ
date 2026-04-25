#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1234567890
using namespace std;

struct line{
	int a,b,cost;
	//정점 a,b간의 비용 cost
};

bool cmp(const line &x, const line &y){
	return x.cost < y.cost;
}
vector<line> lines;

int n,p,a,b,c,cost,edge, MIN=INF;
int arr[10000+5];//arr[i] : i노드를 방문할때 드는 비용 


//MST 크루스칼 - 유니온파인드 
int parent[10000+5];
int find(int a){
	if(parent[a] < 0) return a;
	return parent[a] = find(parent[a]);
}

int merge(int a, int b){
	a = find(a);
	b = find(b);
	if(a==b) return 0;
	
	parent[a] += parent[b];
	parent[b] = a;
	return 1;
}


int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n>>p;
	fill(parent, parent+n+1, -1);
	for(int i=1;i<=n;i++) {
		cin>>arr[i];
		MIN = min(MIN, arr[i]);
		//시작점은 가장 비용이 적은곳으로 선택 
	}
	
	for(int i=0;i<p;i++){
		cin>>a>>b>>c;
		c = arr[a] + arr[b] + 2*c;//가중치 그래프 변형시키기 
		//1. MST에서 모든 간선은 두번씩 이동한다 
		//2. 어느 간선을 지나는것은  두 정점을 지난다는 것이다. 
		lines.push_back({a,b,c});
	}
	
	
	sort(lines.begin(), lines.end(), cmp);
	
	//크루스칼 
	for(int i=0;i<lines.size();i++){
		if(merge(lines[i].a, lines[i].b)){
			cost += lines[i].cost;
			if(++edge == n-1) break;
		}
	}
	
	cout<<cost+MIN;
	return 0;
}