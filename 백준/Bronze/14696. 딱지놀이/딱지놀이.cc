#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int aa[5];// 세모 네모 동그라미 별 1~4
int bb[5];
int a, b, tmp;
int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		memset(aa, 0, sizeof(aa));
		memset(bb, 0, sizeof(bb));

		scanf("%d", &a);
		for (int i = 0; i < a; i++)
		{
			scanf("%d",&tmp);
			aa[tmp]++;
		}
		scanf("%d", &b);
		for (int i = 0; i < b; i++)
		{
			scanf("%d", &tmp);
			bb[tmp]++;
		}
		//입력 끝

		for (int i = 4; i >=1; i--) // 별부터 비교
		{
			if (i == 1 && aa[i] == bb[i]) //모든딱지가 같을때
			{
				printf("D\n");
				break;
			}
			if (aa[i] > bb[i]) //a가 많을때
			{
				printf("A\n");
				break;
			}
			else if (aa[i] < bb[i])
			{
				printf("B\n");
				break;
			}
		}

	}

	return 0;
}

