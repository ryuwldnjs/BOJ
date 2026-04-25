#include <iostream>
using namespace std;
struct node{
	int key;
	node *left;
	node *right;
};

void postorder(node *ptr){ //후위순회 from 킹갓 나동빈's 블로그 
	if(ptr){
		postorder(ptr->left);
		postorder(ptr->right);
		cout<< ptr->key <<'\n';
	}
}

void insert(node *nodes, int key){
	if(key < nodes->key){//왼쪽자식으로 넣어줌 
		if(nodes->left) insert(nodes->left, key);
		else{//왼쪽자식노드 생성 
			nodes->left = new node;
			nodes->left->key = key;
			nodes->left->left = NULL;
			nodes->left->right = NULL;
		}
	}
	else{//오른쪽자식으로
		if(nodes->right) insert(nodes->right, key);
		else{//오른쪽자식노드생성 
			nodes->right = new node;
			nodes->right->key = key;
			nodes->right->left = NULL;
			nodes->right->right = NULL;
		}
	}
	
}
int main(){
	node *root= new node;//이진탐색트리
	root->left = NULL;
	root->right = NULL;
	int a;
	cin>>a;
	root->key = a;

	while(cin>>a) insert(root, a);//삽입 
	
	postorder(root);//후위순회 
	return 0;
}