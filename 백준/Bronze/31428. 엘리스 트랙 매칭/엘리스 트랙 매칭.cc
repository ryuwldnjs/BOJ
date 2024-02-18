#include <bits/stdc++.h>
using namespace std;
unordered_map<char, int> m;
int n;
char x;
int main(){
	cin>>n;
	while(n--){
		cin>>x;
		m[x]++;
	}
	cin>>x;
	cout<<m[x];
	return 0;
}