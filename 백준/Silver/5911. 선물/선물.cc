#include <bits/stdc++.h>
using namespace std;
int n,b,p[1000+5], s[1000+5];
int MAX = 0;
int main(){
	cin>>n>>b;
	for(int i=0;i<n;i++){
		cin>>p[i]>>s[i];
	}
	for(int i=0;i<n;i++){
		vector<long long> tmp;
		for(int j=0;j<n;j++){
			if(i==j) tmp.push_back(p[j]/2 + s[j]);
			else tmp.push_back(p[j] + s[j]);
		}
		sort(tmp.begin(), tmp.end());
		
		long long sum = 0;
		for(int j=0;j<n;j++){
			sum += tmp[j];
			if(sum <= b) MAX = max(MAX, j+1);
		}
	}
	cout<<MAX;
	return 0;
} 