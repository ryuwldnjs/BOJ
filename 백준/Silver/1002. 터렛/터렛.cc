#include <iostream>
using namespace std;
int T,x1,y1,r1,x2,y2,r2;
int main(){
	cin>>T;
	while(T--){
		cin>>x1>>y1>>r1>>x2>>y2>>r2;
		int dist2 = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
		if(r1==r2 && dist2 ==0) cout<<"-1\n";
		else if(dist2 > (r1+r2)*(r1+r2) || dist2 < (r1-r2)*(r1-r2)) cout<<"0\n";
		else if(dist2 == (r1+r2)*(r1+r2) || dist2 == (r1-r2)*(r1-r2)) cout<<"1\n";
		else cout<<"2\n";
	}
	return 0;
}