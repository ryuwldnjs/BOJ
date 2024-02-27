#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false); 
	while(true){
		cin>>n;
		if(n == 0) return 0;
		vector<int> vec(n), tmp(n);
		fill(tmp.begin(), tmp.begin() + 6, 1);
		
		
		for(int i=0;i<n;i++) cin>>vec[i];
		
		do{
			for(int i=0;i<tmp.size();i++){
				if(tmp[i]) cout<<vec[i]<<' ';
			}
			cout<<'\n';
		}while(prev_permutation(tmp.begin(), tmp.end()));
		
		cout<<'\n';	
	}
	return 0;
}