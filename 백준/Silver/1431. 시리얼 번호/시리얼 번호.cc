#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string> vec;
string s;
int n;
bool cmp(string a, string b){
	if(a.size() != b.size()) return a.size() < b.size();
	int sum_a=0, sum_b=0;
	for(int i=0;i<a.size();i++){
		sum_a += '0'<=a[i]&&a[i]<='9' ? a[i]-'0' : 0;
		sum_b += '0'<=b[i]&&b[i]<='9' ? b[i]-'0' : 0;
	}
	if(sum_a != sum_b) return sum_a < sum_b;
	return a < b;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s; vec.push_back(s);
	}
	sort(vec.begin(), vec.end(), cmp);
	for(int i=0;i<n;i++){
		cout<<vec[i]<<'\n';
	}
	return 0;
}