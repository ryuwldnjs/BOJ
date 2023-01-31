#include <iostream>
using namespace std;

int a,b,cnt;
int main(){
	cin>>a>>b;

	while(a < b){
		if(b%10 == 1) b /= 10;
		else if(b%2 == 0) b/=2;
		else break;
		cnt++;
	}
	if(a == b) cout<<cnt+1;
	else cout<<-1;
	return 0;
}