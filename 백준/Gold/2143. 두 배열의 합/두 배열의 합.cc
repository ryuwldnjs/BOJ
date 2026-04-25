#include <iostream>
#include <map>
using namespace std;

map<long long, int> M;
long long t, n,m, x, Apsum[1005], Bpsum[1005], sum;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>t;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		Apsum[i] = Apsum[i-1]+x;
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>x;
		Bpsum[i] = Bpsum[i-1]+x;
	}
	
	//부분합 
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			long long A = Apsum[i] - Apsum[j];
			M[A]++;
		}
	}
	
	//A + B = t -> A = t - B
	for(int i=1;i<=m;i++){
		for(int j=0;j<i;j++){
			long long B = Bpsum[i] - Bpsum[j];
			sum += M[t-B];
		}
	}
	cout<<sum;
	return 0;
}