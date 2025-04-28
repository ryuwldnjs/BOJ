#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > tree; //머지소트트리 
int arr[500000+5];
int n;
//머지소트 
void merge(vector<int> &left, vector<int> &right, vector<int> &parent){
	int n1 = left.size();
	int n2 = right.size();
	
	int i=0, j=0;
	while(i!=n1 || j!=n2){
		if(i==n1){
			parent.push_back(right[j++]);
			continue;
		}
		if(j==n2){
			parent.push_back(left[i++]);
			continue;
		}
		
		
		if(left[i] <= right[j])
			parent.push_back(left[i++]);
		else
			parent.push_back(right[j++]);
		
	}
}

//머지소트트리 구성 
void init(int L, int R, int node){
	if(L==R){
		tree[node].push_back(arr[L]);
		return;
	}
	
	int mid = (L+R)/2;
	init(L, mid, 2*node);
	init(mid+1, R, 2*node+1);
	
	merge(tree[2*node], tree[2*node+1], tree[node]);
}

//[0~i]구간에서 value보다 작은 값의 개수구하는 쿼리 
int query(int node_L, int node_R, int node, int L, int R, int value){
	//구간을 완전히 벗어나는 경우 
	if(R<node_L || node_R<L) return 0;
	
	if(L<=node_L && node_R<=R){
		return lower_bound(tree[node].begin(), tree[node].end(), value) - tree[node].begin();
	}
	int mid = (node_L+node_R)/2;
	return query(node_L, mid, 2*node, L, R, value) + query(mid+1, node_R, 2*node+1, L, R, value);
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	tree.resize(4*n);
	init(0, n-1, 1);
	
	for(int i=0;i<n;i++)
		cout<<i+1 - query(0, n-1, 1, 0, i, arr[i])<<'\n';

	return 0;
} 