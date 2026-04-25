#include <iostream>
#include <string>
using namespace std; 
int main(){
	string str, UCPC="UCPC";
	int k=0;
	while(cin>>str){
		for(int i=0;i<str.size();i++)
			if(str[i]==UCPC[k])
				k++;
			
		if(k==4){
			cout<<"I love UCPC";
			return 0;
		}
	}
	cout<<"I hate UCPC";
	return 0;
}