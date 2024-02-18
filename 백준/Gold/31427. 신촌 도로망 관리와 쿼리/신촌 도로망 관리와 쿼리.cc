#include <bits/stdc++.h>
using namespace std;
unordered_map<string, vector<int>> um;
int n,m,q;
vector<pair<int,int>> road[5];//idx학교의 도로들
vector<int> order={0,1,2,3,4};
vector<int> selected, parent;
int a,b,c;
char z;
void init(){
	selected = vector<int>(5);
	parent = vector<int>(n+1, -1);
} 
int find(int x){
	if(parent[x] < 0) return x;
	
	return parent[x] = find(parent[x]);
}
int merge(int a, int b){
	a = find(a);
	b = find(b);
	
	if(a == b) return 0;
	parent[a] += parent[b];
	parent[b] = a;
	return 1;
}
string makeOrder(vector<int>& arr){
	string tmp;
	for(int n : arr) tmp += to_string(n);
	return tmp;
}
int main(){
	cin>>n>>m>>q;
	for(int i=0;i<m;i++){
		cin>>a>>b>>z; //학교 0,1,2,3,4 
		road[z-'A'].push_back({a,b});
	}
	
	do{//모든 경우 다 탐색
		init(); 
		for(int idx : order){
			for(int i=0;i<road[idx].size();i++){
				if(merge(road[idx][i].first, road[idx][i].second))
					selected[idx]++;
			}
//	printf("aa ");
		}
		
		um[makeOrder(order)] = selected; //order순서일때 각 학교가 해당되는 도로 개수 	
	}while(next_permutation(order.begin(), order.end()));
	
	while(q--){
		vector<pair<int,int>> cost,tmp;
		vector<int> arr;
		long long answer = 0;
		for(int i=0;i<5;i++){
			cin>>c;
			cost.push_back({c,i});
		}
		tmp = cost; //정렬전 백업 
		sort(cost.begin(), cost.end());
		for(int i=0;i<5;i++){
			arr.push_back(cost[i].second);
		}
		
		for(int i=0;i<5;i++){
			answer += (long long)um[makeOrder(arr)][i] * tmp[i].first;
		}
		cout<<answer<<'\n';
	}
	return 0;
}