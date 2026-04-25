#include <iostream>
#include <map>
using namespace std;
double grade;
char a,b;
map<char, double> m;
int main(){
	
	m['A'] = 4.0;
	m['B'] = 3.0;
	m['C'] = 2.0;
	m['D'] = 1.0;
	m['F'] = 0.0;
	scanf("%c%c", &a, &b);
	grade = m[a];
	
	if(b=='+') grade += 0.3;
	else if(b=='-') grade -= 0.3;
	
	
	printf("%.1lf", grade);
	return 0;
} 