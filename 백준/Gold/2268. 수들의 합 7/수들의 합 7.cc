#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

vector<ll> rangeSum;
//세그먼트 트리 -구간합 구하기 


//질의2 - 구간합 구하기 
ll sum(int L, int R, int node, int node_L, int node_R){//구간합 구하기 
	if(R<node_L || node_R<L) return 0;
	if(L<=node_L && node_R<=R) return rangeSum[node];
	
	int mid = (node_L+node_R)/2;
	return sum(L,R,node*2,node_L,mid) + sum(L,R,node*2+1,mid+1,node_R);
}

//질의1 - 값 갱신하기 
ll modify(int idx, int newValue, int node, int node_L, int node_R){
	if(idx < node_L || node_R < idx)
		return rangeSum[node]; //상관없는 구간은 무시 
	if(node_L == node_R) return rangeSum[node] = newValue;
	
	int mid = (node_L+node_R)/2;
	return rangeSum[node] = modify(idx, newValue, node*2, node_L, mid) + modify(idx, newValue, node*2+1, mid+1, node_R);	
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n,m;
	int a,b,c;//각 질의 
	cin>>n>>m;

	rangeSum.resize(4*n, 0);
//	init(0, n-1, 1);//arr전체범위를 포함하는 1번node 출동 - 이문제에서는 생략 
	
	for(int i=0;i<m;i++){ //질의 
		cin>>a>>b>>c;
		
		if(a==0){
			if(b > c) swap(b, c);
			cout<<sum(b-1, c-1, 1, 0, n-1)<<'\n';
		}
		else modify(b-1, c, 1, 0, n-1);//구간합 출력 
			
	}
	return 0;
}