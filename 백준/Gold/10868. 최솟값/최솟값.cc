#include <iostream>
#include <vector>
#include <algorithm>
#define INF 0x7FFFFFFF
using namespace std;

vector<int> arr, RMQ; //Range Minimum Query 구간최소쿼리 


int init(int L, int R, int node){
	if(L==R) return RMQ[node] = arr[L];
	
	int mid = (L+R)/2;
	return RMQ[node] = min(init(L, mid, node*2), init(mid+1, R, node*2+1)); 
}


int query(int L, int R, int node, int node_L, int node_R){//[L,R]은 찾고자 하는 구간, [node_L, node_R]은 현재 구간 
	if(R<node_L || node_R<L) return INF;
	
	if(L<=node_L && node_R<=R) return RMQ[node];
	
	int mid = (node_L+node_R)/2;
	return min(query(L, R, node*2, node_L, mid), query(L, R, node*2+1, mid+1, node_R));
}

/*//이 문제에서는 갱신 필요없음 
int update(int idx, int newValue, int node, int node_L, int node_R){
	if(idx<node_L || node_R<idx) //갱신하고자 하는 node와 상관없는 구간일경우  
		return RMQ[node];
		
	if(node_L == node_R) return RMQ[node] = newValue;
	
	int mid = (node_L+node_R)/2;
	return RMQ[node] = min((idx, newValue, node*2, node_L, mid), update(idx, newValue, node*2+1, mid+1, node_R));
}
*/


int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n,m;
	int a,b;
	cin>>n>>m;
	arr.resize(n+1);//주어지는 배열 
	RMQ.resize(4*n); //세그먼트 트리 노드 개수 설정 적당히 4n개면 된다. 
	for(int i=0;i<n;i++) cin>>arr[i];
	init(0, n-1, 1); //세그먼트 트리 초기 구성 
	
	
	for(int i=0;i<m;i++){
		cin>>a>>b;
		cout<<query(a-1, b-1, 1, 0, n-1)<<'\n';
	}
	return 0;
}