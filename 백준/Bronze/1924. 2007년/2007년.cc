#include<stdio.h>
int month, day;
int tot_day;
int arr[13]={0, 31,28,31,30,31,30,31,31,30,31,30,31};
char what_day[7][7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main()
{
	scanf("%d %d", &month, &day);
	tot_day+=day-1;
	for(int i=1;i<month;i++)
	{
		tot_day+=arr[i];
	}
	printf("%s", what_day[tot_day%7]);
	return 0;
}