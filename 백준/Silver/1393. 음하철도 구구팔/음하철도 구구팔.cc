#include <iostream>
#define INF 1e9;
using namespace std;
int s_x,s_y;
int e_x,e_y,dx,dy;
int ans_x,ans_y, min_dist=INF;

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}
int main(){
	cin>>s_x>>s_y;
	cin>>e_x>>e_y>>dx>>dy;
	int tmp = gcd(dx,dy);
	dx /= tmp;
	dy /= tmp;
	
	for(int i=0;i<200+5;i++){
		int dist = (s_x-e_x)*(s_x-e_x) + (s_y-e_y)*(s_y-e_y);
		if(dist < min_dist){
			min_dist = dist;
			ans_x = e_x;
			ans_y = e_y;
		}
		e_x += dx;
		e_y += dy;
	}
	
	cout<<ans_x<<' '<<ans_y;
	return 0;
}