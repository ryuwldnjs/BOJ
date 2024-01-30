#include <iostream>
using namespace std;
int tmp, n;
char answer[1000000];

void solve(int start, int size){
	if(size == 1){
		answer[start] = '-';
		return;
	}
	solve(start, size/3);
	solve(start + 2*size/3, size/3);
}
int pow3(int exp){
	int result = 1;
	while(exp--){
		result *= 3;
	}
	return result;
}

int main(){
	tmp = pow3(12);
	fill(answer, answer + tmp, ' ');
	solve(0, tmp);
	
	while(cin>>n){
		int end = pow3(n);
		for(int i=0;i<end;i++) cout<<answer[i];
		cout<<'\n';
	}
	return 0;
}