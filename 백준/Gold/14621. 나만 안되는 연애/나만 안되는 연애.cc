#include <iostream>
#include <algorithm>

using namespace std;
struct Edge{
	int u,v,cost;
};
Edge e[10000+5];
bool comp(const Edge e1, const Edge e2){
	return e1.cost < e2.cost;
}

char gender[1000+5];//각 학교별 남초 또는 여초 

//유니온파인드 
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

int n,m, sum,cnt;
int a,b,c;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>gender[i];
	fill(parent+1, parent+n+1, -1);
	
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		e[i]={a,b,c};
	}
	sort(e, e+m, comp);
	
	for(int i=0;i<m;i++){
		if(gender[e[i].u]!=gender[e[i].v] && merge(e[i].u, e[i].v)){
			//연결시킬 두 정점이 서로 다른 성별일때 
			sum += e[i].cost;
			cnt++;
		}
		if(cnt==n-1) break;
	}
	if(cnt!=n-1) cout<<"-1";
	else cout<<sum;
	return 0;
}