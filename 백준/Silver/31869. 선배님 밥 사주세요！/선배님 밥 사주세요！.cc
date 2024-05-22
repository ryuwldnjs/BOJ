#include <iostream>
#include <map>
#include <string>
using namespace std;
using pii=pair<int,int>;
map<string, pii> m;
int n,w,d,p;
string s;
int calendar[80], answer;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s>>w>>d>>p;
		int date = 7*w + d;
		m[s] = {date, p};
	}
	for(int i=0;i<n;i++){
		cin>>s>>p;
		if(m[s].second > p){
			m.erase(s);
		}
	}
	for(auto it=m.begin(); it!= m.end(); it++){
		calendar[it->second.first] = 1;
	}
	answer = calendar[0];
	for(int i=1;i<77;i++){
		if(calendar[i] && calendar[i-1]){
			calendar[i] = calendar[i-1] + 1;
		}
		answer = max(answer, calendar[i]);
	}
	
	cout<<answer;
}