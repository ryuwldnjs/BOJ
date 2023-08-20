    #include <iostream>
#include <unordered_map>
#define INF 100000000
using namespace std;
unordered_map<double, int> m;
double slope;
int n,x,y,cnt;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++){
		
		cin>>x>>y;
		if(x == 0) slope = (double)INF;
		else slope = (double)y/x;
		if(x < 0) slope *= -1;
		if(++m[slope] == 1) cnt++;
	}
	
	cout<<cnt;
	return 0;
}