#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;
int arr[100000+5];
vector<vector<int> > tree;//머지소트트리 
int n,m,a,b,c;


//병합정렬 부분 활용 
void merge(vector<int> &left, vector<int> &right, vector<int> &parent){
	int n1 = left.size();
	int n2 = right.size();
	int i=0,j=0;
	while(i!=n1 || j!=n2){
		if(i==n1){
			parent.push_back(right[j++]);
			continue;
		}
		if(j==n2){
			parent.push_back(left[i++]);
			continue;
		}
		
		if(left[i] <= right[j]){
			parent.push_back(left[i++]);
		}
		else{
			parent.push_back(right[j++]);
		}
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
	
	//머지소트 
	merge(tree[2*node], tree[2*node+1], tree[node]);
}

//k보다 큰 원소 개수 구하는 쿼리 
int query(int node_L, int node_R, int node, int L, int R, int value){
	if(R < node_L || node_R < L) return 0;
	
	//완전히 겹치는 구간 
	if(L<=node_L && node_R<=R){
		return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), value);
		
	}
	
	int mid=(node_L+node_R)/2;
	return query(node_L, mid, 2*node, L, R, value) + query(mid+1, node_R, 2*node+1, L, R, value);
} 

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	tree.resize(4*n);
	init(0, n-1, 1);
	
	cin>>m;
	int prev_ans=0;
	for(int t=0;t<m;t++){
		cin>>a>>b>>c;
		
		int i = a^prev_ans;
		int j = b^prev_ans;
		int k = c^prev_ans;
		
		prev_ans=query(0, n-1, 1, i-1, j-1, k);//i~j중에서 k보다 큰 원소의 개수 
		cout<<prev_ans<<'\n';
	}
	return 0;
}