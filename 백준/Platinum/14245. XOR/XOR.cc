#include <iostream>
#include <vector>
using namespace std;
vector<int> arr,segtree,lazy;
int n,m,a,b,c,d;
//Lazy Propagation - Segment Tree


void init(int L, int R, int node){
	if(L==R){
		segtree[node] = arr[L];
		return;
	}
	int mid = (L+R)/2;
	init(L, mid, 2*node);
	init(mid+1, R, 2*node+1);
}

//지연전파 
void propagate(int L, int R, int node){
	if(!lazy[node]) return;
	
	if(L!=R){
		lazy[2*node] ^= lazy[node];
		lazy[2*node+1] ^= lazy[node];
	}else segtree[node] ^= lazy[node];
	lazy[node] = 0;
}


void update(int node_L, int node_R, int node, int L, int R, int k){
	propagate(node_L, node_R, node);
	
	if(R < node_L || node_R < L) return;
	if(L <= node_L && node_R <= R){
		lazy[node] ^= k;
		propagate(node_L, node_R, node);
		return;
	}
	
	int mid = (node_L+node_R)/2;
	update(node_L, mid, 2*node, L, R, k);
	update(mid+1, node_R, 2*node+1, L, R, k);
}

int query(int node_L, int node_R, int node, int L, int R){
	propagate(node_L, node_R, node);
	
	if(R < node_L || node_R < L) return 0;
	if(L<=node_L && node_R <= R) return segtree[node];
	
	int mid = (node_L+node_R)/2;	
	return query(node_L, mid, 2*node, L, R) ^ query(mid+1, node_R, 2*node+1, L, R);
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n;
	arr.resize(n), segtree.resize(4*n), lazy.resize(4*n);
	for(int i=0;i<n;i++) cin>>arr[i];


	init(0,n-1,1); 
	//리프노드만 고려한 세그트리 구축 
	
	
	cin>>m;
	while(m--){//쿼리 
		cin>>a;
		if(a==1){
			cin>>b>>c>>d;
			update(0,n-1,1,b,c,d);
		}
		else{
			cin>>b;
			cout<<query(0, n-1, 1, b,b)<<'\n';
		}
	} 
	return 0;
}