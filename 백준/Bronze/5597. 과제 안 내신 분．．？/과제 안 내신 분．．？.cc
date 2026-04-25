#include <iostream>
using namespace std;
int n;
bool attend[31];
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	for(int i=0;i<28;i++){
		cin>>n;
		attend[n]=true;
	}
	for(int i=1;i<=30;i++){
		if(!attend[i]) cout<<i<<"\n";
	}
	return 0;
} 