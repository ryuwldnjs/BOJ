#include <iostream>
#include <algorithm>
#define INF 1234567890

using namespace std;

int n,m,b, map[505][505];
int MIN = INF;
int ans_level;

int solve(int level){
	int block = b;
	int cost = 0; 
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map[i][j] > level){ //level보다 높아서 깎아야 할때 
				block += map[i][j] - level;
				cost += (map[i][j] - level) * 2; //깎는 비용 
				//map[i][j] = level;
			}
			else{//level보다 낮을때 
				block -= level - map[i][j];
				cost += level - map[i][j];
				//map[i][j] = level;
			}
			
		}
	}
	
	return block>=0 ? cost : INF;
}
int main(){
	cin>>n>>m>>b;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
		}
	}
	
	for(int i=0;i<=256;i++){
		int cost_i = solve(i); //높이i일떄 땅고르기 cost 
		if(cost_i <= MIN){
			MIN = cost_i;
			ans_level = i;
		}
		
	}
	
	cout<<MIN<<' '<<ans_level;
	return 0;
}