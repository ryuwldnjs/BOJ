#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int n, m, k; //여 남 인턴
	int cnt = 0;//팀 수
	scanf("%d %d %d", &n, &m, &k);

	while (true)
	{
		if (n + m - 3 < k) //한팀 더 짰을때 인턴 참가불가능하면
			break;
		if (n < 2 || m < 1) //더이상 팀 못짜면
			break;

		n -= 2, m -= 1;
		cnt++;
	}
	printf("%d", cnt);
	return 0;
}

