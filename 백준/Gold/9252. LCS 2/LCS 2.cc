#include <iostream>
#include <string>
using namespace std;
using pii=pair<int,int>;
string str1, str2;
int dp[1005][1005];
pii track[1005][1005];

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>str1>>str2;
	str1 = " " + str1;
	str2 = " " + str2;
	
	for(int i=1;i<str1.size(); i++){
		for(int j=1;j<str2.size();j++){
			if(str1[i] == str2[j]){
				dp[i][j] = dp[i-1][j-1] + 1;
				track[i][j] = {i-1, j-1};
			}
			else if(dp[i-1][j] > dp[i][j-1]){
				dp[i][j] = dp[i-1][j];
				track[i][j] = {i-1, j};
			}
			else{
				dp[i][j] = dp[i][j-1];
				track[i][j] = {i, j-1};
			}
		}
	}
	int i=str1.size()-1;
	int j=str2.size()-1;
	string answer;
	while(i || j){
		if(str1[i] == str2[j]) answer = str1[i] + answer;
		auto next = track[i][j];
		i = next.first;
		j = next.second;
	}
	
	cout<<answer.size();
	if(answer.size()) cout<<'\n'<<answer;
	return 0;
}