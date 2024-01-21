#include <iostream>
#include <algorithm>
using namespace std;

int n,m,k;
int card[4000000+50];
int parent[4000000+50];
int find(int x){
	if(parent[x] < 0)
		return x;
	return find(parent[x]);
}

int merge(int a, int b){ //인덱스 기준 a와 b 
	a = find(a);
	b = find(b);
	
	if(a == b) return 0;
	
	parent[a] += parent[b];
	parent[b] = a; // a를 b의 부모로 삼음 
	return 1;
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n>>m>>k;
	fill(parent, parent + m, -1);
	for(int i=0;i<m;i++){
		cin>>card[i];
	}
	sort(card, card+m);
	
	while(k--){
		int x;
		cin>>x;
		
		//해당카드보다 큰 최솟값 찾기 
		int target = upper_bound(card, card+m, x) - card;
		//남아있는 카드중 최솟값 찾기 
		target = find(target); 
		merge(target+1, target); 
		cout<<card[target]<<'\n';
	}
	return 0;
}