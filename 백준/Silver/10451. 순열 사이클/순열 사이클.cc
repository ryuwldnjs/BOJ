#include <stdio.h>
#include <algorithm>
using namespace std;
int p[1010];
int cnt;
void solve(int n)
{
	int tmp = p[n];
	p[n] = 0;
	if (p[tmp] != 0)
		solve(tmp);

}
int main()
{
	int t,n;

	scanf("%d", &t);
	while (t--)
	{	cnt = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &p[i]);
		}

		for (int i = 1; i <= n; i++)
		{
			if (p[i] != 0)
				solve(i), cnt++;
		}
		printf("%d\n", cnt);

	}
	return 0;
}

