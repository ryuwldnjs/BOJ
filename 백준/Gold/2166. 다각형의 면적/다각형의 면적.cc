#include <iostream>
#include <algorithm>
using namespace std;
struct stats{
	long long x,y;
};
stats pos[10000+5];
double answer;
int n;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>pos[i].x>>pos[i].y;
	}
	pos[n] = pos[0];
	
	for(int i=1;i<=n;i++){
		answer += pos[i].x*pos[i-1].y - pos[i].y*pos[i-1].x;
	}
	answer/=2; 
	printf("%.1lf", abs(answer));
}