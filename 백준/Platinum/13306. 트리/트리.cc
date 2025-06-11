#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// Offline Query - 쿼리의 순서가 의존적이지 않은 쿼리 
// 유리한 순서로 바꾸어 해결할 수 있음 

int p[200000+5];//p[i] : 초기 i의 부모
int query[400000+5][3];//쿼리들을 전부 담고, 유리한 순서대로 뽑아씀  
int N,Q;


//유니온 파인드 
int parent[200000+5]; //parent[i] : 현재 유니온파인드도중 i의 부모 
int find(int a){
	if(parent[a] < 0) return a;
	return parent[a] = find(parent[a]);
}
bool merge(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return false;
	
	parent[a] += parent[b]; //a,b의 자손 개수를 합침 
	parent[b] = a;
	return true;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>N>>Q;
	
	fill(parent, parent+N+1, -1);
	for(int i=2;i<=N;i++) cin>>p[i];
	
	for(int i=0;i<N-1+Q;i++){
		cin>>query[i][0];
		if(query[i][0]) cin>>query[i][1]>>query[i][2];
		else cin>>query[i][1];
	}
	
	
	stack<bool> answer;
	for(int i=N-2+Q;i>=0;i--){
		//1쿼리의 경우 초기의 자기 부모와 Union 
		if(!query[i][0]) merge(query[i][1], p[query[i][1]]);
		else{//같은 집합인지 확인 
			int a = find(query[i][1]), b = find(query[i][2]);
			answer.push( a==b ? true : false );
		}
	}
	
	while(!answer.empty()){
		cout<< (answer.top() ? "YES\n" : "NO\n");
		answer.pop(); 
	}
	return 0;
}