#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int n, answer;
string s;
unordered_map<string, int> m;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		if(s == "ENTER") m =  unordered_map<string, int>();
		else if(m[s]++ == 0) answer++; 
	}
	cout<<answer;
	return 0;
}