#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
using namespace std; 
int n;
map<string, int> count;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		string s;cin>>s;
		
		for(int i=0;i<s.size();i++){
			if(s[i] == '.'){
				s[i] = ' ';
			}
		}
		stringstream ss(s);
		string _,ext; ss>>_>>ext;
		count[ext]++;
	}
	
	for(auto it = count.begin(); it!=count.end(); it++){
		cout<<it->first<<' '<<it->second<<'\n';
	}
	return 0;
}