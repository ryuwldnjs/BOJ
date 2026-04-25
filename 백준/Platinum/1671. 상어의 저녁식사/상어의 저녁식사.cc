#include <iostream>
#include <vector>
using namespace std;

vector<int> arr[55];
int stats[55][3];
bool  visited[55];
vector<int> predator(55,-1), prey(55,-1);
int n, answer, death;

//이분매칭  
bool dfs(int a){
	if(visited[a]) return false;
	visited[a] = true;
	
	for(int i=0;i<arr[a].size();i++){
		int b = arr[a][i];
		
		if(prey[b] == -1 || dfs(prey[b])){
			prey[b] = a;
			predator[a] = b;
			return true;
		}
	}
	return false;
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>stats[i][0];
		cin>>stats[i][1];
		cin>>stats[i][2];
	}
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){

			if(stats[i][0] >= stats[j][0] && stats[i][1] >= stats[j][1] && stats[i][2] >= stats[j][2]){
				arr[i].push_back(j);
			}
			else if(stats[i][0] <= stats[j][0] && stats[i][1] <= stats[j][1] && stats[i][2] <= stats[j][2]){
				arr[j].push_back(i);
			}
		}
	}
	
	//한마리당 최대 2마리가능하므로, 2번 flow를 흘려준다. 
	for(int k=0;k<2;k++)
	for(int i=0;i<n;i++){
		fill(visited, visited+n, false);
		if(dfs(i)) death++;
	}
	answer = n-death;
	cout<<answer;
	return 0;
}