#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll=long long;
int match[1000000+50];
int match2[500000+50];
vector<int> arr; 
vector<vector<int>> tree; //머지소트트리 
int n,a;
ll ans;
//병합정렬 응용 
void merge(vector<int> &left, vector<int> &right, vector<int> &parent){
	int n1 = left.size();
	int n2 = right.size();
	int i = 0, j = 0;
	while(i != n1 || j != n2){
		if(i == n1){
			parent.push_back(right[j++]);
			continue;
		}
		if(j == n2){
			parent.push_back(left[i++]);
			continue;
		}
		
		if(left[i] <= right[j])
			parent.push_back(left[i++]);
		else
			parent.push_back(right[j++]);
	}
}

void init(int L, int R, int node){
	if(L==R){
		tree[node].push_back(arr[L]);
		return;
	}
	int mid = (L+R) / 2;
	init(L, mid, 2*node);
	init(mid+1, R, 2*node+1);
	
	merge(tree[2*node], tree[2*node+1], tree[node]);
}


ll query(int node_L, int node_R, int node, int L, int R, int value){
	if(R < node_L || node_R < L) return 0;
	
	//완전히 겹치는 구간 
	if(L<=node_L && node_R<=R){
		return (ll) (lower_bound(tree[node].begin(), tree[node].end(), value) - tree[node].begin());
		
	}
	
	int mid=(node_L+node_R)/2;
	return query(node_L, mid, 2*node, L, R, value) + query(mid+1, node_R, 2*node+1, L, R, value);
} 


int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n;
	arr.resize(n);
	for(int i=0;i<n;i++){
		cin>>a;
		match[a] = i;
		match2[i] = a;
	}
	for(int i=0;i<n;i++){
		cin>>a;
		arr[match[a]] = i;
	}
	tree.resize(4*n);
	init(0, n-1, 1);
	for(int i=0;i<n;i++){
		ans += query(0, n-1, 1, i+1, n-1, arr[i]);
		//cout<<arr[i];
	}
	cout<<ans;
	return 0;
}