#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

vector<ll> rangeSum, array;
//세그먼트 트리 -구간합 구하기 

ll init(int L, int R, int node){
	if(L==R)
		return rangeSum[node] = array[L];
	int mid = (L+R)/2;
	ll leftMin = init(L, mid, node*2);
	ll rightMin = init(mid+1, R, node*2+1);
	return rangeSum[node] = leftMin + rightMin;
} 

//질의2 - 구간합 구하기 
ll query(int L, int R, int node, int node_L, int node_R){//구간합 구하기 
	if(R<node_L || node_R<L) return 0;
	if(L<=node_L && node_R<=R) return rangeSum[node];
	
	int mid = (node_L+node_R)/2;
	return query(L,R,node*2,node_L,mid) + query(L,R,node*2+1,mid+1,node_R);
}

//질의1 - 값 개신하기 
ll update(int idx, ll newValue, int node, int node_L, int node_R){
	if(idx < node_L || node_R < idx)
		return rangeSum[node]; //상관없는 구간은 무시 
	if(node_L == node_R) return rangeSum[node] = newValue;
	
	int mid = (node_L+node_R)/2;
	return rangeSum[node] = update(idx, newValue, node*2, node_L, mid) + update(idx, newValue, node*2+1, mid+1, node_R);	
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n,m,k;
	ll a,b,c;//각 질의 
	cin>>n>>m>>k;
	array.resize(n+2);
	rangeSum.resize(4*n);
	for(int i=0;i<n;i++) cin>>array[i];
	init(0, n-1, 1);//arr전체범위를 포함하는 1번node 출동 
	
	for(int i=0;i<m+k;i++){ //질의 
		cin>>a>>b>>c;
		if(a==1) update(b-1, c, 1, 0, n-1);//갱신 
		else cout<<query(b-1, c-1, 1, 0, n-1)<<'\n';//구간합 출력 
	}
	return 0;
}