#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,a,b;
vector<int> prime[2];
int psum1[50000],psum2[50000];
void makePrime(){
	prime[0].push_back(0); 
	prime[1].push_back(0); 
	int idx=0;
	for(int i=2;i<=100000;i++){
		bool isPrime = true;
		for(int j=2;j*j<=i;j++){
			if(i%j == 0){
				isPrime = false;
				break;
			}
		}
		if(isPrime) prime[(idx++)%2].push_back(i);
	}
	
	for(int i=1;i<prime[0].size();i++){
		psum1[i] = psum1[i-1] + prime[0][i];
//		printf("%d ", prime[0][i]);
	}
//	printf("\n");
	for(int i=1;i<prime[1].size();i++){
		psum2[i] = psum2[i-1] + prime[1][i];
//		printf("%d ", prime[1][i]);
	}
}

int solve(){
	int s1 = lower_bound(prime[0].begin(), prime[0].end(), a) - prime[0].begin();
	int e1 = upper_bound(prime[0].begin(), prime[0].end(), b) - prime[0].begin();
	int ans1 = psum1[e1-1] - psum1[s1-1];
	
	int s2 = lower_bound(prime[1].begin(), prime[1].end(), a) - prime[1].begin();
	int e2 = upper_bound(prime[1].begin(), prime[1].end(), b) - prime[1].begin();
	int ans2 = psum2[e2-1] - psum2[s2-1];
	
	if(prime[0][s1] < prime[1][s2]){
//		printf("%d, %d\n", ans1, ans2);
		return 3*ans1 - ans2;
	}
	else{
//		printf("%d, %d\n", ans1, ans2);
		return 3*ans2 - ans1;
	}
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n;
	makePrime();
	while(n--){
		cin>>a>>b;
		cout<<solve()<<'\n';
	}
	return 0;
}