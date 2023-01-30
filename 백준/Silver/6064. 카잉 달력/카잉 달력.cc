#include <iostream>

using namespace std;
int T,m,n,x,y;
int main(){
	
	cin>>T;
	
	while(T--){
		cin>>m>>n>>x>>y;
		
		int a=0, b=0;
		while(1){
			int first = m*a + x;
			int second = n*b + y;
			if(first < second) a++;
			else if(first > second) b++;
			else break;
			
			if(a>n || b>m) {
				cout<<"-1\n";
				goto a;
			}
		}
		
		cout<<m*a + x<<'\n';
		a:;
	}
	return 0;
}