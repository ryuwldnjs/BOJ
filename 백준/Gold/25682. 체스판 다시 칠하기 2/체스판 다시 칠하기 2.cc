#include <iostream>
#define INF 1234567890
using namespace std;

int n,m,k;
char x;
int psum[2005][2005];
int MIN = INF;
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>x;
			if((i+j)%2 == 0 && x == 'B' || (i+j)%2 == 1 && x == 'W'){
				//잘못된 체스판인경우 (그냥 이걸 잘못된경우라고 가정) 
				psum[i][j] = 1;
			}
			psum[i][j] += psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
		}
	}
	
	for(int i=k;i<=n;i++){
		for(int j=k;j<=m;j++){
			int repaint = psum[i][j] - psum[i-k][j] - psum[i][j-k] + psum[i-k][j-k];
			MIN = min(MIN, repaint < k*k - repaint ? repaint : k*k - repaint);
//			printf("%d\n", MIN); 
		}
	}
	cout<<MIN;
	return 0;
}