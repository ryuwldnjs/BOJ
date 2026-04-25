#include <iostream>
#include <vector>
using namespace std;
vector<long long> arr, segtree, lazy;
long long n,m,k,a,b,c,d;
long long init(int L, int R, int node){
	if(L==R) return segtree[node] = arr[L];
	
	int mid = (L+R)/2;
	return segtree[node] = init(L,mid,2*node) + init(mid+1, R, 2*node+1);
}


//지연전파 
void propagate(int L, int R, int node){
	if(lazy[node] != 0){
		if(L!=R){
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}
		segtree[node] += lazy[node]*(R-L+1);
		lazy[node] = 0;
	}
} 

//구간 [L, R]에 k더하기 
long long update(int node_L, int node_R, long long k, int node, int L, int R){
	propagate(node_L, node_R, node);
	
	if(R < node_L || node_R < L) return segtree[node];
	if(L <= node_L && node_R <=R){
		lazy[node] += k;
		propagate(node_L, node_R, node);
		return segtree[node];
	}
	
	int mid = (node_L+node_R)/2;	
	return segtree[node] = update(node_L, mid, k, 2*node, L, R) +  update(mid+1, node_R, k, 2*node+1, L, R);
}


//구간 s~e의 합 
long long query(int node_L, int node_R, int node, int L, int R){
	propagate(node_L, node_R, node);
	
	if(R < node_L || node_R < L) return 0;
	
	if(L <=node_L && node_R <=R) return segtree[node];
	
	int mid = (node_L+node_R)/2;
	return query(node_L, mid, 2*node, L, R) + query(mid+1, node_R, 2*node+1, L, R);
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n>>m>>k;
	arr.resize(n), segtree.resize(4*n), lazy.resize(4*n);
	for(int i=0;i<n;i++) cin>>arr[i];
	init(0, n-1, 1);
	
	
	for(int i=0;i<m+k;i++){
		cin>>a>>b>>c;
		if(a==1){
			cin>>d;
			update(0 ,n-1, d, 1, b-1, c-1);
		}
		else{
			cout<<query(0,n-1, 1, b-1, c-1)<<'\n';
		}
	}
	return 0;
}