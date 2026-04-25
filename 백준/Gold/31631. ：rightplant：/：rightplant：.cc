#include <iostream>
#include <vector>
using namespace std;
int n;


int main(){
	cin>>n;
	vector<int> answer(n);
	int target = n;
	for(int i=0;i<n/2;i++){
		if(i%2==0){
			answer[n-1-i] = target--;
			answer[i] = target--;
		}
		else{
			answer[i] = target--;
			answer[n-1-i] = target--;
		}
	}
	if(answer[n/2] == 0) answer[n/2] = 1;
	for(auto i : answer) cout<<i<<' ';
	return 0;
}