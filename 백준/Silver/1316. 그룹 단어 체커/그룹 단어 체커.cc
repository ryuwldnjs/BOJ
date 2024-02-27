#include <bits/stdc++.h>
using namespace std;
int n,answer;
string str;
int main(){
	cin>>n;
	while(n--){
		cin>>str;
		str.erase(unique(str.begin(), str.end()), str.end());
		set<char> s(str.begin(), str.end());
		if(str.size() == s.size()) answer++;
	}
	cout<<answer;
	return 0;
}