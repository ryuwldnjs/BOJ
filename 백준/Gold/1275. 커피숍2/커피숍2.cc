#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;
vector<long long> arr, rangeSum; 


//초기 설정 
long long init(int L, int R, int node){
	if(L==R) return rangeSum[node] = arr[L];
	int mid = (L+R)/2;
	
	return rangeSum[node] = init(L, mid, 2*node) + init(mid+1, R, 2*node+1);
}


//구간 합 구하기 
long long query(int L, int R, int node, int node_L, int node_R){
	if(R<node_L || node_R<L) return 0;
	
	if(L<=node_L && node_R<=R) return rangeSum[node];//범위에 완전히 속할때 
	int mid = (node_L+node_R)/2;
	return query(L, R, 2*node, node_L, mid) + query(L, R, 2*node+1, mid+1, node_R);
}




long long update(int idx, int newValue, int node, int node_L, int node_R){
	if(idx<node_L || node_R<idx) return rangeSum[node];
	
	if(node_L==node_R) return rangeSum[node] = newValue;
	
	int mid = (node_L+node_R)/2;
	return rangeSum[node] = update(idx, newValue, 2*node, node_L, mid) + update(idx, newValue, 2*node+1, mid+1, node_R);
}


int n,q;
int x,y,a,b;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n>>q;
	arr.resize(n+1), rangeSum.resize(4*n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	init(0, n-1, 1);
	
	for(int i=0;i<q;i++){
		cin>>x>>y>>a>>b;
		if(x>y) swap(x,y);
		cout<<query(x-1, y-1, 1, 0, n-1)<<'\n';
		update(a-1, b, 1, 0, n-1);
	}
	return 0;
}