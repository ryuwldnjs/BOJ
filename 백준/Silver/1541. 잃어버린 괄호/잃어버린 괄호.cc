#include <iostream>
#include <string>
using namespace std;

string str;
int num, sum;
int sign = 1;
int main(){
	cin>>str;
	
	for(int i=0;i<str.size(); i++){
		if(isdigit(str[i])){
			num *= 10;
			num += str[i] - '0';
		}
		else{ //연산자	 
			sum += sign * num;
			num = 0;
			if(str[i] == '-') sign = -1; //마이너스 만나는 순간부터 전부 빼기 연산 
		}	
	}
	
	sum += sign * num;
	cout<<sum;
	return 0;
} 