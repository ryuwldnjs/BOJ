#include <iostream>
#include <vector>
using namespace std;
using pii=pair<int, int>; 
struct Line{
	pii start, end;
};
Line L[3005];
int n, MAX=1;
vector<int> parent(3005, -1);

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

int CCW(pii a, pii b, pii c){
	int op =  a.first*b.second + b.first*c.second + c.first*a.second	
				-( a.second*b.first + b.second*c.first + c.second*a.first);
	if(op > 0) return 1;
	else if(op == 0) return 0;
	else return -1;
}

//교차판정 
bool isIntersect(Line a, Line b){
	int ab = CCW(a.start, a.end, b.start) * CCW(a.start, a.end, b.end);
	int cd = CCW(b.start, b.end, a.start) * CCW(b.start, b.end, a.end);
	if(ab==0 && cd==0){
		return max(a.start, a.end) >= min(b.start, b.end) && min(a.start, a.end) <= max(b.start, b.end);
	}
	return ab<=0 && cd<=0;
}


int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		L[i] = {{a,b}, {c,d}};
	}
	int group = n;
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(isIntersect(L[i], L[j]) && merge(i,j)){
				group--;
				MAX = max(MAX, -parent[find(i)]);//최상단 조상의 parent값은 해당 컴포넌트의 노드 개수 
			}
		}
	}
	cout<<group<<'\n'<<MAX;
	return 0;
}