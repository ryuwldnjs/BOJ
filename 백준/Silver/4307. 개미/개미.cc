#include <stdio.h>
#include <algorithm>
using namespace std;
int t,len,n;
int ans_min, ans_max;
int ant;
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		ans_min=0, ans_max=0;
		scanf("%d %d", &len, &n);
		for(int i=0;i<n;i++)
		{
			scanf("%d", &ant);
			//최솟값 
			int left= ant;
			int right = len - ant;
			ans_min = max(ans_min, min(left, right));
			//최댓값 
			ans_max = max(ans_max, max(left, right));
			
			
		}
		
		printf("%d %d\n", ans_min, ans_max);
	}
	return 0;
}