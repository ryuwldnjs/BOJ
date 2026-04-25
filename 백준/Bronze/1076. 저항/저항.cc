//#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
string color[10]={"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
string a,b,c;
long long ans;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> a>>b>>c;
	for(int i=0;i<10;i++){
		if(a==color[i]) ans += i*10; //첫번째 색 
		if(b==color[i])	ans += i; //두번째 색 a
	}
	for(int i=0;i<10;i++){
		if(c==color[i]){
		int tmp=i;
		while(tmp--){
			ans*=10;
			}
		}
	}
	cout << ans;
	return 0;
}