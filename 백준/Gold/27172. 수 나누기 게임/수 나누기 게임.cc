#include <iostream>
#include <algorithm> 
using namespace std;
int n,x;
int card[100000+5], arr[1000000+5];
int score[100000+5];

void solve(int num, int target){
	for(int i=1;i*i<=num;i++){
		if(num%i != 0) continue;
		if(arr[i]){
			int winner = arr[i];
			score[winner]++;
			score[target]--;
		}
		if(arr[num/i] && i*i!=num && i != 1){
			int winner = arr[num/i];
			score[winner]++;
			score[target]--;
		}
	}
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>card[i];
		arr[card[i]] = i;
	}
	
	for(int i=1;i<=n;i++){ solve(card[i], i); }
	
	for(int i=1;i<=n;i++){
		cout<<score[i]<<' ';
	}
	return 0;
}