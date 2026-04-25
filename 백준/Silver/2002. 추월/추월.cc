#include <iostream>
#include <map>
using namespace std;

map<string, int> car;
int n, answer, after[1005];
string str;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>str;
		car[str] = i;
	}
	for(int i=0;i<n;i++){
		cin>>str;
		after[i] = car[str];
	}
	
	for(int i=0;i<n;i++){
		int target = after[i];
		
		for(int j=i+1;j<n;j++){
			if(target > after[j]){
				answer++;
				break;
			}
		}
	}
	cout<<answer;
	return 0;
}