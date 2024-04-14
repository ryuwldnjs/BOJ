#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,d;
bool isAnswer = true;
vector<vector<int>> students;
int main(){
	cin>>n>>m>>d;
	students = vector<vector<int>>(n, vector<int>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>students[i][j];
			students[i][j] += d*i; //층 고려 
		}
	}
	for(auto &s : students){
		sort(s.begin(), s.end());
	}

	for(int j=0;j<m;j++){
		int MAX = -1;
		for(int i=0;i<n;i++){
			if(MAX >= students[i][j]) isAnswer = false;
			MAX = max(MAX, students[i][j]);
		}
	}
	cout<<(isAnswer ? "YES" : "NO");
	return 0;
}