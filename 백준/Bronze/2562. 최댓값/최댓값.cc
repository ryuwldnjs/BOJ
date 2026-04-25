#include <iostream>
using namespace std; 
int n, MAX_idx, MAX = -1;
int main(){
	for(int i=0;i<9;i++){
		cin>>n;
		if(n > MAX){
			MAX = n;
			MAX_idx = i+1;
		}
	}
	cout<<MAX<<"\n"<<MAX_idx;
	return 0;
}