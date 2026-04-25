#include <iostream>
using namespace std;

int n,m,cnt=1;
int main(){
	cin>>n>>m;
	for(int a=0;a<2;a++){
		for(int b=0;b<2;b++){
			for(int c=0;c<2;c++){
				for(int d=0;d<2;d++){
					int time = a*n + b*(n/2) + c*(n/2 + n%2) + d*((2+n)/3);
					if(time > m) continue;//시간초과 
					if(a^b^c&&!(a*b*c) || !(a+b+c)&&d) {
					//	printf("%d %d %d %d\n",a,b,c,d);
						cnt++;
					}
					
				}
			}
		}
	}
	if(n==1) cnt = 1 + !!m; // 1층이고 제한시간이 1초이상이면 2가지면 
	else if(n==2) cnt = m>=2 ? 4 : 1+(2*m);
	cout<<cnt;
	return 0;
}