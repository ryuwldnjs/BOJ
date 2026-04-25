#include <stdio.h>
#include <algorithm>
using namespace std;
int n, now, cnt;
pair<int, int> time[100000+100]; // 끝,시작 시간 
int main()
{
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d", &time[i].second, &time[i].first);
	}
	sort(time, time+n);
	
	now = time[0].first;
	cnt++;
	for(int i=1;i<n;i++)
	{
		if (time[i].second>=now)
		{
			now = time[i].first;
			cnt++;
		}
	}
	
	printf("%d", cnt);
	return 0;
}