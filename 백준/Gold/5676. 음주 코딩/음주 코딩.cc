#include <iostream>
#include <vector>
using namespace std;

struct stats{
	int minus;
	bool zero;
	
	stats operator+ (const stats& p){
		return {minus+p.minus, zero||p.zero};
	}
};
//구간 음수 개수와 0개수만 체크
 
int n,k;
int b,c;
char a;
vector<stats> rangePro;//구간 곱
vector<int> arr; 

stats init(int L, int R, int node){
	stats tmp={0,false};
	if(L == R){
		if(arr[L]<0)
			tmp.minus = 1;
		else if(arr[L]==0)
			tmp.zero = true;
			
		return rangePro[node] = tmp;
	}
	
	int mid = (L+R)/2;	
	return rangePro[node] = init(L, mid, 2*node) + init(mid+1, R, 2*node+1);
}


stats query(int L, int R, int node, int node_L, int node_R){
	if(R<node_L || node_R<L) return {0, false};
	
	if(L<=node_L && node_R<=R)
		return rangePro[node];
	
	int mid = (node_L+node_R)/2;
	return query(L, R, 2*node, node_L, mid) + query(L, R, 2*node+1, mid+1, node_R);
}

stats update(int idx, int newValue, int node, int node_L, int node_R){
	if(idx<node_L || node_R<idx) return rangePro[node];
	
	if(node_L==node_R){
		if(newValue==0)
			return rangePro[node] = {0,true};
		else if(newValue<0)
			return rangePro[node] = {1,false};
		else
			return rangePro[node] = {0, false};
	}
	
	int mid = (node_L+node_R)/2;
	
	return rangePro[node] = update(idx, newValue, 2*node, node_L, mid) + update(idx, newValue, 2*node+1, mid+1, node_R);
}


int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	while(cin>>n){
		rangePro.clear(), arr.clear();
		rangePro.resize(4*n), arr.resize(n);
		
		cin>>k;
		for(int i=0;i<n;i++) cin>>arr[i];
		
		init(0,n-1, 1);

		for(int i=0;i<k;i++){
			cin>>a>>b>>c;
			
			if(a == 'C') update(b-1, c, 1, 0, n-1);
			else{
				stats tmp = query(b-1, c-1, 1, 0, n-1);
				
				if(tmp.zero)
					cout<<0;
				else if(tmp.minus%2==1)
					cout<<'-';
				else
					cout<<'+';
			}
		}
		
		//테스트케이스 한줄 끝 
		cout<<'\n';
	}
	return 0;
}