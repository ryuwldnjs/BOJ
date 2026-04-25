#include <iostream>
#include <vector>
using namespace std;
struct info{
	int node;//연결된 노드 
	int cost;//비용 
};

vector<info> tree[10000+5];
bool visited[10000+5];
int MAX_cost, MAX_node;

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
	cin>>n, n--; //대체 왜 n입력해놓고, n-1번 반복함?? 
	while(n--){ 
		cin>>a>>b>>cost;
		tree[a].push_back({b,cost});
		tree[b].push_back({a,cost});
	}
	
	DFS(1, 0); //1번node에서 제일 cost가 큰 노드가 원지름의 한 점이다. 
	fill(visited, visited+10005, 0);
	
	DFS(MAX_node, 0);//원지름의 한 점에서 start 
	cout<<MAX_cost; 
	return 0;
}