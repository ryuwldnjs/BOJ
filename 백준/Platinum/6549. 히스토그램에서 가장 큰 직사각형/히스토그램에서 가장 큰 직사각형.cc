#include <iostream>
#include <vector>
#define INF 1234567890
using namespace std; 

struct stats{
	int val;
	int idx;
/*	stats operator< (const stats &p){
		if(val<p.val) return {val, idx};
		return p;
	}*/	
};

int n;

vector<int> arr;
vector<stats> rangeMin;

stats min(stats a, stats b){
	if(a.val <= b.val) return a;
	return b;
}

stats init(int L, int R, int node){
	if(L==R) return rangeMin[node] = {arr[L], L};
	
	int mid = (L+R)/2;
	return rangeMin[node] = min(init(L, mid, 2*node), init(mid+1, R, 2*node+1));
}

stats query(int L, int R, int node, int node_L, int node_R){
	if(R<node_L || node_R<L) return {INF, -1};
	if(L<=node_L && node_R<=R) return rangeMin[node];
	
	int mid = (node_L+node_R)/2;
	return min(query(L, R, 2*node, node_L, mid), query(L, R, 2*node+1, mid+1, node_R));
}



//분할정복 + 세그트리 
long long solve(int s, int e){
	if(s==e) return (long long)arr[s];//가로가1이고 높이가arr[s]인 도형 넓이 반환
	if(s>e) return -1LL; //불가능한 경우
	 
	stats min = query(s, e, 1, 0, n-1);//해당구간의 최솟값과 인덱스를 불러옴 
	long long area = (long long)min.val*(e-s+1);//구할수있는 직사각형 넓이 반환
	
	return max(area, max(solve(s, min.idx-1), solve(min.idx+1, e)));
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	while(true){
		cin>>n;
		if(!n) break;
		
		arr.clear(), rangeMin.clear();
		arr.resize(n), rangeMin.resize(4*n);
		for(int i=0;i<n;i++) cin>>arr[i];
		
		init(0, n-1, 1);

		cout<<solve(0, n-1)<<'\n';
	}
	return 0;
}