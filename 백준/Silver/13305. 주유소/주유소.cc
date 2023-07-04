#include<iostream>
#define INF 1234567890
using namespace std;
using ll=long long;

ll n,dist[100000+5], cost[100000+5];
ll MIN = INF;
ll sum;
int main(){
	cin>>n;
	for(int i=0;i<n-1;i++)
		cin>>dist[i];
		
	for(int i=0;i<n;i++)
		cin>>cost[i];
		
		
	for(int i=0;i<n-1;i++){
		MIN = min(MIN, cost[i]);
		sum += MIN * dist[i];
	}
	
	cout<<sum;
	return 0;
}