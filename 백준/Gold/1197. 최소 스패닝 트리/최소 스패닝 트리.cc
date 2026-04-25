#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge{
	int u,v,w;
	bool operator <(const Edge& O)const{
		return w<O.w;
	}
};
vector<Edge> vec;
int parent[100000+5];

int find(int a){
	if(parent[a] < 0) return a;
	return parent[a] = find(parent[a]); 
}

int merge(int a, int b){
	a = find(a);
	b = find(b);
	
	if(a==b) return false; //이미 같은 컴포넌트 인경우
	 
	parent[b] = a; //유니온
	return true; 
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int v,e;
	int a,b,c, sum=0, cnt=0;
	cin>>v>>e;
	for(int i=1;i<=v;i++) parent[i]=-1;//음수는 자기자신을 나타냄 
	
	for(int i=0;i<e;i++){
		cin>>a>>b>>c;
		vec.push_back({a,b,c});
	}
	sort(vec.begin(), vec.end());
	
	for(int i=0;i<e;i++){
		if(merge(vec[i].u, vec[i].v)){//유니온 성공시 
			sum += vec[i].w;
			cnt++;
			if(cnt==v-1) break;
		}
	}
	
	cout<<sum;
	return 0;
}