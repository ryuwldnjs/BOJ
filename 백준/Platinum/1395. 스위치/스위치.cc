#include <iostream>
#include <vector>
using namespace std;

// Lazy Propagation - Segment Tree
// 스위치 특성상 XOR 1 연산으로 쉽게 표현 가능 

vector<int> arr, segtree, lazy;
int n,m,a,b,c;

//전파
void propagate(int L, int R, int node){
	if(!lazy[node]) return;
	if(L!=R){
		lazy[2*node] ^=1;
		lazy[2*node+1] ^=1;
	}
	segtree[node] = (R-L+1) - segtree[node];
	lazy[node] = 0;
}

int update(int L, int R, int node, int node_L, int node_R){
	propagate(node_L, node_R, node);
	
	if(R < node_L || node_R < L) return segtree[node];
	if(L <= node_L && node_R <= R){
		lazy[node] ^= 1;
		propagate(node_L, node_R, node);
		return segtree[node];
	}
	
	int mid =(node_L+node_R)/2;
	return segtree[node] = update(L, R, 2*node, node_L, mid) + update(L, R, 2*node+1, mid+1, node_R);
}

int query(int L, int R, int node, int node_L, int node_R){
	propagate(node_L, node_R, node);
	
	if(R < node_L || node_R < L) return 0;
	if(L <= node_L && node_R <= R) return segtree[node];
	
	int mid = (node_L+node_R)/2;
	
	return query(L, R, 2*node, node_L, mid) + query(L, R, 2*node+1, mid+1, node_R);
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n>>m;
	arr.resize(n), segtree.resize(4*n), lazy.resize(4*n);
	//init(0, n-1, 1);
	//초기에 전부 0이므로 init() 불필요
	
		
	while(m--){
		cin>>a>>b>>c;
		if(a) cout<<query(b-1, c-1, 1, 0, n-1)<<'\n';
		else update(b-1, c-1, 1, 0, n-1);
	}
	return 0;
}