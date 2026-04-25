#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

typedef long long ll;
vector<ll> arr, rangeProduct;


ll init(int L, int R, int node){
	if(L==R) return rangeProduct[node] = arr[L];
	
	int mid = (L+R)/2;
	return rangeProduct[node] = init(L, mid, node*2) * init(mid+1, R, node*2+1) % MOD; 
}


ll product(int L, int R, int node, int node_L, int node_R){//[L,R]은 찾고자 하는 구간, [node_L, node_R]은 현재 구간 
	if(R<node_L || node_R<L) return 1;
	
	if(L<=node_L && node_R<=R) return rangeProduct[node];
	
	int mid = (node_L+node_R)/2;
	return product(L, R, node*2, node_L, mid) * product(L, R, node*2+1, mid+1, node_R) % MOD;
}


ll update(int idx, int newValue, int node, int node_L, int node_R){
	if(idx<node_L || node_R<idx) //갱신하고자 하는 node와 상관없는 구간일경우  
		return rangeProduct[node];
		
	if(node_L == node_R) return rangeProduct[node] = newValue;
	
	int mid = (node_L+node_R)/2;
	return rangeProduct[node] = update(idx, newValue, node*2, node_L, mid) * update(idx, newValue, node*2+1, mid+1, node_R) % MOD;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n,m,k;
	int a,b,c;
	
	cin>>n>>m>>k;
	arr.resize(n+1);//주어지는 배열 
	rangeProduct.resize(4*n); //세그먼트 트리 노드 개수 설정 적당히 4n개면 된다. 
	for(int i=0;i<n;i++) cin>>arr[i];
	init(0, n-1, 1); //세그먼트 트리 초기 구성 
	
	
	for(int i=0;i<m+k;i++){
		cin>>a>>b>>c;
		if(a==1) update(b-1, c, 1, 0, n-1);
		else cout<<product(b-1, c-1, 1, 0, n-1)<<'\n';
	}
	return 0;
}