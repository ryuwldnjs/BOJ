#include <iostream>
#define BIAS 3500000
using namespace std;

int memo[7000000+5];
int n,s,arr[45];
long long answer;
void solve1(int now, int sum){
	if(now == n/2){
		memo[sum + BIAS]++;
		return;
	}
	
	solve1(now+1, sum);
	solve1(now+1, sum + arr[now]);
}


void solve2(int now, int sum){
	if(now == n){
		int target = s - sum + BIAS;
		answer += memo[target];
		return;
	}
	
	solve2(now+1, sum);
	solve2(now+1, sum + arr[now]);
}

int main(){
	cin>>n>>s;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	solve1(0, 0);
	solve2(n/2, 0);
	
	if(s==0) answer--;
	cout<<answer;
	return 0;
}