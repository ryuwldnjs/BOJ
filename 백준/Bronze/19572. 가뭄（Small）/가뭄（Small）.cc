#include <iostream>
using namespace std;
double d1,d2,d3;
double a,b,c;
int main(){
	cin>>d1>>d2>>d3;
	double all = d1+d2+d3;
	
	c = all/2. - d1; 
	b = all/2. - d2; 
	a = all/2. - d3;
	
	if(a<=0 || b<=0 || c<=0){
		cout<<-1;
		return 0;
	}
	printf("1\n%.1lf %.1lf %.1lf", a,b,c); 
	return 0;
}