#include <iostream>
#include <map>
using namespace std;
map<string, int> m;
int n,MAX;
string s,ans;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		m[s]++;
	}
	for(auto it = m.begin(); it != m.end(); it++){
		if(MAX < it->second){
			ans = it->first;
			MAX = it->second;
		}
	}
	cout<<ans;
	return 0;
}