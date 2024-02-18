#include <bits/stdc++.h>
using namespace std;
int n,head=1;
string s,school[500000+5];
int child[500000+5], tail[500000+5];
int a,b;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) {
		child[i] = tail[i] = i;
	}
	for(int i=1;i<=n;i++) {
		cin>>s;
		school[i] = s;
	}
	for(int i=0;i<n-1;i++){
		cin>>a>>b;
		if(head == b) head = a;
		child[tail[a]] = b;
		tail[a] = tail[b]; //꼬리 확장 
	}
	string answer;
	for(int i=head,j=0;j<n;i = child[i],j++){
		answer += school[i];
	}
	cout<<answer;
	return 0;
}