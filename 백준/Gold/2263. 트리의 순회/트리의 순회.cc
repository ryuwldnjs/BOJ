#include <iostream>
using namespace std;

pair<int, int> tree[100000+5]; //이진트리 
int inorder[100000+5];
int postorder[100000+5];
int index[100000+5];
int solve(int in_L, int in_R, int post_L, int post_R){//중위순회[L,R], 후위순회[L,R] 
	int root = postorder[post_R]; //후위순회 마지막은 root 
	
	if(in_L >= in_R){
		return root;
	}
	
	int pivot = index[root];
	if(pivot - post_L)
		tree[root].first = solve(in_L, pivot-1, post_L, post_L+pivot-in_L-1); //pivot-in_L=서브트리의 구간 길이 
	if(in_R-pivot)
		tree[root].second = solve(pivot+1, in_R, post_L+pivot-in_L, post_R-1);
	return root;
}

void preorder(int node){//전위 순회 
	if(node){
		cout<<node<<' ';
		preorder(tree[node].first);
		preorder(tree[node].second);
	}
}

int main(){
	int n, k;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>inorder[i];
		index[inorder[i]] = i;//inorder[i]의 위치 저장 
	}
	for(int i=1;i<=n;i++) cin>>postorder[i];
	
	solve(1,n,1,n);
	preorder(postorder[n]);
	return 0;
}