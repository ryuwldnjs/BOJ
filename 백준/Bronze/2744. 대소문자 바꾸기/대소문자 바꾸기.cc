#include <iostream>
#include <string>

using namespace std;
string str;
int main(){
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i] >= 'a' ) //소문자 
			str[i] = toupper(str[i]);
		else
			str[i] = tolower(str[i]);
	}
	cout<<str;
	return 0;
}