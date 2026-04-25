#include <iostream>
#include <map>
using namespace std;
int k; 
map<int, bool> m;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	for(int i=0;i<10;i++){
		cin>>k;
		m[k%42] = true;
	}
	cout<<m.size();
	return 0;
}