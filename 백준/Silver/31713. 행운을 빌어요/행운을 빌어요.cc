#include <iostream>
using namespace std;
int t,a,b;
int main(){
	cin>>t;
	while(t--){
		cin>>a>>b;
		int answer = 0;
		while(true){
			if(3*a <= b&&b <=4*a){
				cout<<answer<<'\n';
				break;
			}
			else if(4*a < b){
				int gap = (b-4*a+3)/4;
				a += gap;
				answer += gap;
			}
			else if(b < 3*a){
				int gap = 3*a - b;
				b += gap;
				answer += gap;
			}
		}
	}
	return 0;
}