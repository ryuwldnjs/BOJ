#include <bits/stdc++.h>
using namespace std;
int t,n,a,b;
vector<int> overlap;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		overlap = vector<int>(200+1);
		
		for(int i=0;i<n;i++){
			cin>>a>>b;
			
			a = (a-1)/2;
			b = (b-1)/2;
			if(a > b) swap(a,b);
			
			for(int pos = a; pos<=b; pos++){
				overlap[pos]++;
			}
		}
		int MAX = -1;
		for(int i=0;i<=200;i++){
			MAX = max(MAX, overlap[i]);
		}
		cout<<MAX*10<<'\n';
	}
	return 0;
}