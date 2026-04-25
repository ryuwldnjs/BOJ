#include <iostream>
#include <string>
using namespace std;
string map[10][10];

int main(){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			cin>>map[i][j];
		}
	}
	
	for(int i=0;i<10;i++){
		string target = map[i][0];
		bool isAnswer = true;
		for(int j=0;j<10;j++){
			if(target != map[i][j]) isAnswer = false;
		}
		if(isAnswer){
			cout<<1;
			return 0;
		}
	}
	for(int i=0;i<10;i++){
		string target = map[0][i];
		bool isAnswer = true;
		for(int j=0;j<10;j++){
			if(target != map[j][i]) isAnswer = false;
		}
		if(isAnswer){
			cout<<1;
			return 0;
		}
	}
	cout<<0;
	return 0;
}