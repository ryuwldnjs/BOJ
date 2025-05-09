#include <iostream>
using namespace std;
struct Node{//이진트리 
	char data;
	Node *left;
	Node *right;
};


void preorder(Node *node){//전위 순회 
	if(node){
		cout<<node->data;
		preorder(node->left);
		preorder(node->right);
	}
}

void inorder(Node *node){//중위 순회 
	if(node){
		inorder(node->left);
		cout<<node->data;
		inorder(node->right);
	}
}

void postorder(Node *node){//후위 순회 
	if(node){
		postorder(node->left);
		postorder(node->right);
		cout<<node->data;
	}
}

Node tree[27];
int main(){
	char a,left,right;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>left>>right;
		int idx = a-'A';// 그냥 i써도 됨 
		tree[idx].data = a;
		//tree[idx].left = tree[idx].right = NULL;
		if(left!='.')
			tree[idx].left = &tree[left-'A'];
		if(right!='.')
			tree[idx].right = &tree[right-'A'];
	}
	preorder(tree); //&tree[0]과 동일 
	cout<<'\n';
	inorder(tree);
	cout<<'\n';
	postorder(tree);
	return 0;
}