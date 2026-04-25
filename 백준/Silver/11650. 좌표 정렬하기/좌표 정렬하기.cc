#include <iostream>
#include <algorithm>
using namespace std;
int n; 
pair<int,int> m[100000+50];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin >> m[i].first >> m[i].second;
	sort(m, m+n);

	for(int i=0;i<n;i++)
		cout << m[i].first <<' '<< m[i].second<<'\n';
	
	return 0;
}