#include <bits/stdc++.h>
using namespace std;
int n, answer;
string str;
int main(){
	cin>>n>>str;
	unordered_map<char, int> m;
	int l = 0, r = 0;
	int cnt=1;
	m[str[0]]++;
	while(true){
		if(cnt <= n){
			answer = max(answer, r-l+1);
			if(r==str.size()-1) break;
			if(m[str[++r]]++ == 0) cnt++;
		}
		else{
			if(--m[str[l++]] == 0) cnt--;
		}
	}
	cout<<answer;
	return 0;
}