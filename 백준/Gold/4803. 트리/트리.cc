#include <iostream>
#include <vector> 
#define hasCycle -100000
using namespace std;
vector<int> parent;
int n,m, case_num, answer;
vector<int> banned;
int find(int x){
	if(parent[x] < 0) return x;
	return parent[x] = find(parent[x]);
}
int merge(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return 0;
	parent[b] = a;
	return 1;
}
int main(){
	while(++case_num){
		cin>>n>>m;
		parent = vector<int>(n+1, -1);
		banned = vector<int>();
		answer = n;
		
		if(n==0 && m==0) break;
		
		for(int i=0;i<m;i++){
			int a,b; cin>>a>>b;
			
			if(merge(a,b)) answer--;
			else banned.push_back(a); //넌 트리가 아니다 
//			printf("%d\n", answer);
		}
		for(int x : banned){
			x = find(x);
			if(parent[x] == hasCycle) continue;
			parent[x] = hasCycle;
			answer--;
		}
		
		cout<<"Case "<<case_num<<": ";
		if(answer == 0) cout<<"No trees.\n";
		else if(answer == 1) cout<<"There is one tree.\n";
		else cout<<"A forest of "<<answer<<" trees.\n";
		
	}
	return 0;
}