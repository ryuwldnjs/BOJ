#include <iostream>
using namespace std;
int psum[200000+5][30]; // psum[n][a] : 인덱스n까지의 a의 개수 
string str,c;
int q,a,b;
int main(){
	cin>>str;
	cin>>q;
	for(int i=0;i<str.size();i++){
		for(int j=0;j<='z'-'a';j++){
			psum[i+1][j] = psum[i][j];
			if(str[i] - 'a' == j) psum[i+1][j]++;
		}
	}
	
	while(q--){
		cin>>c>>a>>b;
		int alpha = c[0] - 'a';
		a++;b++;
		
		cout<<psum[b][alpha] - psum[a-1][alpha]<<'\n';
		
	}
}