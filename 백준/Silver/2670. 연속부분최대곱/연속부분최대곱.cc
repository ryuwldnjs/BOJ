#include <bits/stdc++.h>
using namespace std;
int n;
double x,result=1,MAX = -1;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		MAX = max(MAX, result = max(result * x, x));
	}
	printf("%.3f", MAX);
}