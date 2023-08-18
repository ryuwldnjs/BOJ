#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> p,m;
bool cmp(int &a, int &b){
	return a > b;
}
int n,x,answer;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		if(x > 1) p.push_back(x);
		else if(x == 1) answer += 1;
		else m.push_back(x);
	}
	sort(p.begin(), p.end(), cmp);
	sort(m.begin(), m.end());
	
	
	for(int i=0;i<(int)p.size()-1;i+=2){
		answer += p[i]*p[i+1];
	}
	
	for(int i=0;i<(int)m.size()-1;i+=2){
		answer += m[i]*m[i+1];
	}
	if(p.size() % 2 == 1) answer += p.back();
	if(m.size() % 2 == 1) answer += m.back();
	cout<<answer;
	return 0;
}