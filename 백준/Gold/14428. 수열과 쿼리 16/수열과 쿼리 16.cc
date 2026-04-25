#include <iostream>
#include <vector>
#define INF 1234567890
using namespace std;
struct stats{
	int val, idx;
};
vector<int> arr;
vector<stats> rangeMin;
stats init(int L, int R, int node){
	if(L==R) return rangeMin[node] = {arr[L], L};
	
	int mid = (L+R)/2;
	stats tmp1, tmp2;
	tmp1 = init(L, mid, 2*node);
	tmp2 = init(mid+1, R, 2*node+1);
	if(tmp1.val <=tmp2.val) return rangeMin[node] = tmp1;
	else return rangeMin[node] = tmp2;
}

stats update(int idx, int newValue, int node, int node_L, int node_R){
	if(idx<node_L || node_R<idx) return rangeMin[node];
	
	if(node_L==node_R) return rangeMin[node] = {newValue, rangeMin[node].idx};
	stats  tmp1, tmp2;
	int mid = (node_L+node_R)/2;
	tmp1 = update(idx, newValue, 2*node, node_L, mid);
	tmp2 = update(idx, newValue, 2*node+1, mid+1, node_R);
	if(tmp1.val <=tmp2.val) return rangeMin[node] = tmp1;
	else return rangeMin[node] = tmp2;
	
	
}
stats query(int L, int R, int node, int node_L, int node_R){
	if(R<node_L || node_R<L) return {INF, INF};//범위를 완전히 벗어날때 
	
	if(L<=node_L && node_R<=R) return rangeMin[node];//범위를 완전히 포함할때 
	stats tmp1, tmp2;
	int mid = (node_L+node_R)/2;
	tmp1 = query(L, R, 2*node, node_L, mid);
	tmp2 = query(L, R, 2*node+1, mid+1, node_R);
	
	if(tmp1.val <=tmp2.val) return tmp1;
	else return tmp2;
}
int n,m,a,b,c;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n;
	arr.resize(n), rangeMin.resize(4*n);
	for(int i=0;i<n;i++) cin>>arr[i];
	
	init(0, n-1, 1);
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		if(a==1) update(b-1, c, 1, 0, n-1);
		else{
			cout<<query(b-1, c-1, 1, 0, n-1).idx+1<<'\n';
		}
	}
	return 0;
}