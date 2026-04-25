#include <iostream>
#include <math.h>
using namespace std; 
long long L_R, s_r; //외접원 내접원 반지름 
int main(){
	cin>>L_R>>s_r;
	long long dist = L_R*L_R - 2*L_R*s_r;
	cout<<dist;
	return 0;
}