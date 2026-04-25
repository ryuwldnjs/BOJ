#include <stdio.h>
#include <algorithm>
using namespace std;
int cost, cnt;
int arr[6] = { 500,100,50,10,5,1 };
int main()
{
	scanf("%d", &cost);

	cost = 1000 - cost;//거스름돈 
	
	for (int i = 0; i < 6; i++)
	{
		if (cost < arr[i])//거슬러 줘야할 돈이 적을 경우
			continue;
		cnt += cost / arr[i];
		cost %= arr[i];
		if (cost <= 0) //거스름돈을 다 줬을때
			break;
	}
	printf("%d", cnt);
	return 0;
}

