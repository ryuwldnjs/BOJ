#include <iostream>
#define INF 1234567890
using namespace std;

int MAX[2][3];
int MIN[2][3];

int n,a,b,c;
int ans_max = -INF, ans_min = INF;
int main(){
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>a>>b>>c;
		
		//max[i][j] = max(max[i-1][0], max[i-1][1], max[i-1][2]);
		MAX[i%2][0] = max(MAX[(i+1)%2][0], MAX[(i+1)%2][1]);
		MAX[i%2][1] = max(MAX[(i+1)%2][0], max(MAX[(i+1)%2][1], MAX[(i+1)%2][2]));
		MAX[i%2][2] = max(MAX[(i+1)%2][1], MAX[(i+1)%2][2]);
		
		MIN[i%2][0] = min(MIN[(i+1)%2][0], MIN[(i+1)%2][1]);
		MIN[i%2][1] = min(MIN[(i+1)%2][0], min(MIN[(i+1)%2][1], MIN[(i+1)%2][2]));
		MIN[i%2][2] = min(MIN[(i+1)%2][1], MIN[(i+1)%2][2]);
		
		MAX[i%2][0] += a;
		MAX[i%2][1] += b;
		MAX[i%2][2] += c;
		
		MIN[i%2][0] += a;
		MIN[i%2][1] += b;
		MIN[i%2][2] += c;
		
	}
	
	for(int i=0;i<3;i++){
		ans_max = max(MAX[(n-1)%2][i], ans_max);
		ans_min = min(MIN[(n-1)%2][i], ans_min);
	}
	
	cout<<ans_max<<' '<<ans_min;
	return 0;
}