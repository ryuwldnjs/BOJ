#include <iostream>
#include <unordered_map>
using namespace std;
int t,n,x;
unordered_map<int, bool> m;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n;
		m = unordered_map<int,bool>();
		for(int i=0;i<n;i++){
			cin>>x; m[x] = true;
		}
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>x; if(m.end() !=m.find(x)) cout<<"1\n"; else cout<<"0\n";
		}
	}
	return 0;
}