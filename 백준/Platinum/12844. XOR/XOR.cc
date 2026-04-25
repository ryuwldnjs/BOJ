#include <iostream>
#include <vector>
using namespace std;

// Lazy Propagation - Segment Tree
vector<int> arr, segtree, lazy;
int n,m,a,b,c,d;

int init(int L, int R, int node){
	if(L==R) return segtree[node] = arr[L];
	
	int mid = (L+R)/2;
	return segtree[node] = init(L, mid, 2*node) ^ init(mid+1, R, 2*node+1);
}

//지연 전파 
void propagate(int L, int R, int node){
	if(!lazy[node]) return;
	
	if(L!=R){
		lazy[2*node] ^= lazy[node];
		lazy[2*node+1] ^= lazy[node];
	}
	if((R-L+1)%2==1) segtree[node] ^= lazy[node];
	lazy[node] = 0; 
}

//구간 XOR 갱신 
int update(int L, int R, int k ,int node, int node_L, int node_R){
	propagate(node_L, node_R, node);
	
	if(R < node_L || node_R < L) return segtree[node];
	if(L <= node_L && node_R <= R){
		lazy[node] ^= k;
		propagate(node_L, node_R, node);
		
		return segtree[node];
	}
	
	int mid = (node_L+node_R)/2;
	
	return segtree[node] = update(L, R, k , 2*node, node_L, mid) ^ update(L, R, k ,2*node+1, mid+1, node_R);	
}

int query(int L, int R, int node, int node_L, int node_R){
	propagate(node_L, node_R, node);
	if(R < node_L || node_R < L) return 0;
	if(L <= node_L && node_R <= R) return segtree[node];
	
	int mid = (node_L+node_R)/2;
	
	return query(L, R, 2*node, node_L, mid) ^ query(L, R, 2*node+1, mid+1 , node_R);
	
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n;
	arr.resize(n), segtree.resize(4*n), lazy.resize(4*n);
	
	for(int i=0;i<n;i++) cin>>arr[i];
	init(0,n-1, 1);
	
	cin>>m;
	while(m--){
		cin>>a>>b>>c;
		if(b>c) swap(b,c);
		
		if(a==1){
			cin>>d;
			update(b, c, d, 1, 0, n-1);
		}
		else{
			cout<<query(b, c, 1, 0, n-1)<<'\n';
		}
	}
	return 0;
}