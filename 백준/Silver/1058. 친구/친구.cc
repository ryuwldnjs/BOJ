#include <iostream>
#define INF 1000000000
using namespace std;
int n, MAX=-1;
int dist[55][55];
char c;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>c;
			if(c == 'N') dist[i][j] = INF;
			else dist[i][j] = 1;
		}
		dist[i][i] = 0;
	}
	
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	
	for(int i=0;i<n;i++){
		int cnt = 0;
		for(int j=0;j<n;j++){
			if(dist[i][j] == 1 | dist[i][j] == 2) cnt++;
		}
		MAX = max(MAX, cnt);
	}
	
	cout<<MAX;
	return 0;
}