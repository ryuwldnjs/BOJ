#include <iostream>
#include <math.h>
using namespace std;

long long powpow (int base, int power) {
	long long answer=1;
	for(int i=0; i<power;++i){
		answer*=base;
		answer%=1234567891; 
	}
	return answer;
}

int main() {
	
	int L; cin >> L;
	string str; cin >> str;
	int size = str.size();
	long long answer = 0;
	for(int i=0; i<size; ++i) {
		long long num = (int)str[i]-(int)'a'+1;
		answer+=num*powpow(31,i);
	}
	cout << answer << '\n';
	
	
	return 0;
} 