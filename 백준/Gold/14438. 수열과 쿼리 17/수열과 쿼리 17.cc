#include <iostream>
#include <vector>
#include <algorithm>
#define INF 0x7FFFFFFF
using namespace std;

vector<int> arr, rangeMin;



int init(int L, int R, int node){
	if(L==R) return rangeMin[node] = arr[L];
	
	int mid = (L+R)/2;
	return rangeMin[node] = min(init(L, mid, node*2), init(mid+1, R, node*2+1));
}

int update(int idx, int newValue, int node, int node_L, int node_R){
	if(idx<node_L || node_R<idx) return rangeMin[node];
	
	if(node_L == node_R) return rangeMin[node] = newValue;
	int mid=(node_L+node_R)/2;	
	return rangeMin[node] = min(update(idx, newValue, node*2, node_L, mid), update(idx, newValue, node*2+1, mid+1, node_R));
	
}

int query(int L, int R, int node, int node_L, int node_R){ // 찾고싶은 구간 = [L,R]
	if(R<node_L || node_R<L) return INF;
	
	if(L<=node_L && node_R<=R) return rangeMin[node];
	
	int mid = (node_L+node_R)/2;
	return min(query(L, R, node*2, node_L, mid), query(L, R, node*2+1, mid+1, node_R));
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	int a,b,c;
	cin>>n;
	arr.resize(n+1), rangeMin.resize(4*n);
	for(int i=0;i<n;i++) cin>>arr[i];
	init(0, n-1, 1);
	
	cin>>m;
	while(m--){
		cin>>a>>b>>c;
		if(a==1) update(b-1, c, 1, 0, n-1);
		else cout<<query(b-1, c-1, 1, 0, n-1)<<'\n';
	}
	return 0;
}