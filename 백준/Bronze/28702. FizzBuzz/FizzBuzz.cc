#include <iostream>
#include <string>
using namespace std;
string a[3];
int target;
int main(){
	cin>>a[2]>>a[1]>>a[0];
	for(int i=0;i<3;i++){
		string& s = a[i];
		if(s.find("Fizz")!=string::npos || s.find("Buzz")!=string::npos)
			continue;
			
		target = stoi(s) + i+1;
		break;
	}
	if(target%3==0) cout<<"Fizz";
	if(target%5==0) cout<<"Buzz";
	if(target%3 * target%5) cout<<target;
	return 0;
}