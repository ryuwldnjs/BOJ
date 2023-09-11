#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>
using namespace std;

vector<string> name, increasing, decreasing;
bool isInc = true;
bool isDec = true;
int n;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n;
	name.resize(n);
	for(int i=0;i<n;i++){
		cin>>name[i];
	}
	
	increasing = name;
	decreasing = name;
	sort(increasing.begin(), increasing.end());
	sort(decreasing.begin(), decreasing.end(), greater<string>());
	
	for(int i=0;i<name.size();i++){
		if(name[i] != increasing[i])
			isInc = false;
	}
	for(int i=0;i<name.size();i++){
		if(name[i] != decreasing[i])
			isDec = false;
	}
	
	if(isInc == true)
		cout<<"INCREASING";
	else if(isDec == true)
		cout<<"DECREASING";
	else
		cout<<"NEITHER";
	return 0;
}