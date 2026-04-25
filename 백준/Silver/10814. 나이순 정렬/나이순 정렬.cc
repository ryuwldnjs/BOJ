#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int n, age;
string name;
vector<pair<int, string> > v;

bool cmp(pair<int, string> a, pair<int, string> b){
	//if(a.first == b.first) return true;
	return a.first < b.first;
}


int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>age>>name;
		v.push_back({age, name});
	}
	
	stable_sort(v.begin(), v.end(), cmp);
	
	for(int i=0;i<n;i++)
		cout<<v[i].first<<' '<<v[i].second<<'\n';
	return 0;
}