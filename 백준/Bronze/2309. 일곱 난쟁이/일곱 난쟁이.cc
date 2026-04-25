#include <stdio.h>
#include <algorithm>
using namespace std;
int height[9],sum;
int main()
{
	for(int i=0;i<9;i++) {
		scanf("%d", &height[i]);
		sum+= height[i];
	}
	sort(height, height+9);
	sum-=100;
	
	for(int i=1;i<9;i++){
		for(int j=0;j<i;j++){
			if(height[i]+height[j]==sum) {
				for(int k=0;k<9;k++)
				{
					if(k==i||k==j) continue;
					printf("%d\n", height[k]);
				}
				return 0;
			}
		}
	}
	
	return 0;
}