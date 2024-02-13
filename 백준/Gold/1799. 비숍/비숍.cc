#include <bits/stdc++.h>
using namespace std;

int n,x;
vector<int> bishop[20+5];
bool visited[20 + 5];
int solve(int row, int cnt){
//	printf("%d\n", row);
	int MAX = -1;
	if(row >= 2*n - 1) return cnt;
	for(int i=0;i<bishop[row].size(); i++){
		int col = bishop[row][i] + n;
		if(!visited[col]){
			visited[col] = true;
			MAX = max(MAX, solve(row + 2, cnt + 1));
			visited[col] = false;
		}
	}
	return MAX = max(MAX, solve(row + 2, cnt)); //이번 row에는 비숍 안세울거임! 
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>x;
			if(x) bishop[i+j].push_back(i-j);
		}
	}
	cout<<solve(0,0) + solve(1,0);
	//홀수번째 크로스, 짝수번째 크로스는 서로 영향을 안끼침 
	return 0;
}