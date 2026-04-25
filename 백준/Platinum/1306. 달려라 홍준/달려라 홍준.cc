#include <iostream>
#include <vector>
using namespace std;

vector<int> RMQ, arr;

int init(int L, int R, int node){
	if(L==R) return RMQ[node] = arr[L];
	
	
	int mid = (L+R)/2;
	return RMQ[node] = max(init(L, mid, 2*node), init(mid+1, R, 2*node+1));
}

int query(int L, int R, int node, int node_L, int node_R){
	if(R < node_L || node_R < L) return -1;//범위 벗어날 경우
	
	if(L<=node_L && node_R<=R) return RMQ[node];
	//범위에 완전히 속해 있는 경우 
	
	int mid = (node_L+node_R)/2;
	return max(query(L, R, 2*node, node_L, mid), query(L, R, 2*node+1, mid+1, node_R));
}
//이문제에서는 갱신이 필요없으므로 update함수는 생략

 
int n,m;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n>>m;
	arr.resize(n), RMQ.resize(4*n);
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	
	//세그트리 초기 설정 
	init(0, n-1, 1);	
	
	for(int i = m-1;i<n-m+1;i++){
		cout<<query(i-m+1, i+m-1,  1, 0, n-1)<<' ';
	}
	return 0;
}