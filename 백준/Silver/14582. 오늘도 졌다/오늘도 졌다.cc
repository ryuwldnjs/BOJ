#include <bits/stdc++.h>
using namespace std;
int a[10], b[10];
int main(){
	for(int i=0;i<9;i++) cin>>a[i];
	for(int i=0;i<9;i++) cin>>b[i];
	
	int score = 0;
	for(int i=0;i<9;i++){
		score += a[i];
		if(score > 0) {
			cout<<"Yes";
			return 0; 
		}
		score -= b[i];
	}
	cout<<"No";
	return 0;
}