#include <iostream>
using namespace std;
double a;
long long b=100000000; 
int main(){
	
	scanf("%lf", &a);
	for(int i=0;i<8;i++)
		a *= 10.0;
	//printf("%lf\n", a);
	printf("YES\n%lld %lld", (long long)a,b); 
	return 0;
}