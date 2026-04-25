#include <iostream>
#include <vector>
using namespace std;
struct info{
	int node;//연결된 노드 
	int cost;//비용 
};

vector<info> tree[100000+5];
bool visited[100000+5];
long long MAX_cost, MAX_node;

void DFS(int current, int cost){
	visited[current] = true;
	
	if(MAX_cost<cost){
		MAX_cost = cost;
		MAX_node = current;
	}
	
	for(int i=0;i<tree[current].size();i++){
		int next_node = tree[current][i].node;
		int next_cost = tree[current][i].cost;
		if(!visited[next_node]) DFS(next_node, cost + next_cost);
	}
}



int main(){
	int n, a, b, cost;
	cin>>n;
	while(n--){ 
		cin>>a;
		while(true){
			cin>>b;
			if(b==-1) break;
			cin>>cost;
			tree[a].push_back({b, cost});
		}
	}
	
	DFS(1, 0); //1번node에서 제일 cost가 큰 노드가 원지름의 한 점이다. 
	fill(visited, visited+100005, 0);
	
	DFS(MAX_node, 0);//원지름의 한 점에서 start 
	cout<<MAX_cost; 
	return 0;
}