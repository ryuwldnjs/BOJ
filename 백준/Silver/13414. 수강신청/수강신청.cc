#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int k,l;
string s;
map<string, int> priority;
vector<pair<int, string>> result;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>k>>l;
	for(int i=0;i<l;i++){
		cin>>s;
		priority[s] = i;
	}
	for(auto it = priority.begin(); it!=priority.end(); it++){
		result.push_back({it->second, it->first});
	}
	sort(result.begin(), result.end());

	for(int i=0;i<k && i<result.size();i++){
		cout<<result[i].second<<'\n';
	}
	return 0;
}