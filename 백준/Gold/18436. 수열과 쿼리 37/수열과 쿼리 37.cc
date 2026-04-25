#include <iostream>
#include <vector>
#define INF 1234567890
using namespace std;
struct stats{
	int odd, even;//홀짝 
	stats(){
	}
	stats(int a, int b){
		odd=a;
		even=b;
	} 
	
};
vector<int> arr;
vector<stats> rangeCnt;
stats odd(1,0), even(0,1);
stats init(int L, int R, int node){
	if(L==R) return rangeCnt[node] = arr[L]%2==1? odd : even;
	
	int mid = (L+R)/2;
	stats tmp1, tmp2;
	tmp1 = init(L, mid, 2*node);
	tmp2 = init(mid+1, R, 2*node+1);
	return rangeCnt[node] = {tmp1.odd + tmp2.odd, tmp1.even + tmp2.even};//합치는거지 
}

stats update(int idx, int newValue, int node, int node_L, int node_R){
	if(idx<node_L || node_R<idx) return rangeCnt[node];
	
	if(node_L==node_R) return rangeCnt[node] = newValue%2==1?odd:even;
	
	stats  tmp1, tmp2;
	int mid = (node_L+node_R)/2;
	tmp1 = update(idx, newValue, 2*node, node_L, mid);
	tmp2 = update(idx, newValue, 2*node+1, mid+1, node_R);
	return rangeCnt[node] = {tmp1.odd + tmp2.odd, tmp1.even + tmp2.even};
	
	
}
stats query(int L, int R, int node, int node_L, int node_R){
	if(R<node_L || node_R<L) return {0, 0};//범위를 완전히 벗어날때 
	
	if(L<=node_L && node_R<=R) return rangeCnt[node];//범위를 완전히 포함할때 
	stats tmp1, tmp2;
	int mid = (node_L+node_R)/2;
	tmp1 = query(L, R, 2*node, node_L, mid);
	tmp2 = query(L, R, 2*node+1, mid+1, node_R);
	
	return {tmp1.odd + tmp2.odd, tmp1.even + tmp2.even};
}
int n,m,a,b,c;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n;
	arr.resize(n), rangeCnt.resize(4*n);
	for(int i=0;i<n;i++) cin>>arr[i];
	
	init(0, n-1, 1);
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		if(a==1) update(b-1, c, 1, 0, n-1);
		else if(a==2) cout<<query(b-1, c-1, 1, 0, n-1).even<<'\n';
		else cout<<query(b-1, c-1, 1, 0, n-1).odd<<'\n';
	}
	return 0;
}