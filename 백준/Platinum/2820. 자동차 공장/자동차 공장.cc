#include <iostream>
#include <vector>
using namespace std;

vector<int> arr,segtree,lazy;
vector<int> tree[500000+5];
int pos[500000+5], junior[500000+5], w[500000+5];
int n,m,b,c,x;
char a;

//계층구조를 전위순회하면서 arr에 다시 저장 
//자신의 자식이 몇명인지도 체크한후, arr에서 몇명까지가 자기 자식인지도 체크 
int preorder(int x){
	pos[x] = arr.size();//노드x의 arr에서의 새로운 위치를 저장 
	arr.push_back(x);
	
	for(int i=0;i<tree[x].size();i++)
		junior[x] += preorder(tree[x][i]);

	return junior[x] += tree[x].size();
}


//Lazy Propagation - Segment Tree
void init(int L, int R, int node){
	if(L==R){
		segtree[node] = w[arr[L]];
		return;
	}
	
	int mid =(L+R)/2;
	init(L, mid, 2*node), init(mid+1, R, 2*node+1);
}

//지연 전파 
void propagate(int L, int R, int node){
	if(!lazy[node]) return;
	
	if(L!=R){
		lazy[2*node] += lazy[node];
		lazy[2*node+1] += lazy[node];
	}else segtree[node] += lazy[node];
	
	lazy[node] = 0;
}

//리프노드값 갱신만 고려한 세그트리 
void update(int node_L, int node_R, int node, int L, int R, int k){
	propagate(node_L, node_R, node);
	
	if(R < node_L || node_R < L) return;
	if(L <= node_L && node_R <= R){
		lazy[node] += k;
		propagate(node_L, node_R, node);
		return;
	}
	int mid = (node_L+node_R)/2;
	
	update(node_L, mid, 2*node, L, R, k);
	update(mid+1, node_R, 2*node+1, L, R, k);
}

int query(int node_L, int node_R, int node, int L, int R){
	propagate(node_L, node_R, node);
	if(R < node_L || node_R < L) return 0;
	if(L <= node_L && node_R <= R) return segtree[node];
	
	int mid = (node_L+node_R)/2;
	return query(node_L, mid, 2*node, L, R) + query(mid+1, node_R, 2*node+1, L, R);
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n>>m;
	segtree.resize(4*n), lazy.resize(4*n);
	
	cin>>w[1];
	for(int i=2;i<=n;i++){
		cin>>w[i]>>x;
		tree[x].push_back(i);
	}
	
	//트리구조를 전위순회한 후 
	//각 노드별 자손노드 개수 저장 
	preorder(1);
	init(0, n-1, 1);
	
	while(m--){
		cin>>a;
		if(a=='p'){
			cin>>b>>c;
			update(0, n-1, 1, pos[b]+1, pos[b]+junior[b], c);
		}else{
			cin>>b;
			cout<<query(0, n-1, 1, pos[b], pos[b])<<'\n';
		}
	} 
	
	return 0;
}