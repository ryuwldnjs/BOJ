#include <iostream>
#include <math.h>
using namespace std;

int main() {
	
	int L; cin >> L;
	string str; cin >> str;
	int size = str.size();
	int answer = 0;
	for(int i=0; i<size; ++i) {
		int num = (int)str[i]-(int)'a'+1;
		answer+=num*pow(31,i);
	}
	cout << answer << '\n';
	
	
	return 0;
} 