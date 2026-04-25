#include <iostream>

using namespace std;
int T,H,W,N;
int main(){
	scanf("%d", &T);
	
	while(T--){
		scanf("%d %d %d", &H, &W, &N);
		printf("%d%02d\n", (N-1)%H+1, (N-1)/H+1);
	}
	return 0;
}