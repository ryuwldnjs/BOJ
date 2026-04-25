#include <iostream>
#include <vector>
#include <algorithm>
#define INF 0x7FFFFFFF
#define pii pair<int, int>
using namespace std;

vector<int> arr;
vector<pii> rangeMin_Max;//{최소, 최대} 


pii init(int L, int R, int node){
	if(L==R) return rangeMin_Max[node] = {arr[L], arr[L]};
	
	int mid = (L+R)/2;
	
	pii tmp1 = init(L, mid, node*2);
	pii tmp2 = init(mid+1, R, node*2+1);
	
	int MIN = min(tmp1.first, tmp2.first);
	int MAX = max(tmp1.second, tmp2.second);
	return rangeMin_Max[node] = { MIN, MAX };
}



pii query(int L, int R, int node, int node_L, int node_R){ // 찾고싶은 구간 = [L,R]
	if(R<node_L || node_R<L) return {INF, -INF};
	
	if(L<=node_L && node_R<=R) return rangeMin_Max[node];
	
	int mid = (node_L+node_R)/2;
	
	pii tmp1 = query(L, R, node*2, node_L, mid);
	pii tmp2 = query(L, R, node*2+1, mid+1, node_R);
	
	int MIN = min(tmp1.first, tmp2.first);
	int MAX = max(tmp1.second, tmp2.second);
	return { MIN, MAX };
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	int a,b;
	cin>>n>>m;
	arr.resize(n+1), rangeMin_Max.resize(4*n);
	for(int i=0;i<n;i++) cin>>arr[i];
	init(0, n-1, 1);
	
	while(m--){
		cin>>a>>b;
		pair<int, int> tmp = query(a-1, b-1, 1, 0, n-1);
		cout<<tmp.first<<' '<<tmp.second<<'\n';
	}
	return 0;
}