#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;
int n,m,k;
string str[300], answer;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		cin>>str[i];
		sort(str[i].begin(), str[i].end());
	}
	sort(str, str+n);
	for(int i=0;i<k;i++){
		answer += str[i];
	}
	//cout<<answer<<'\n';
	sort(answer.begin(), answer.end());
	cout<<answer;
	return 0;
}