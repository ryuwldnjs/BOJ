#include <stdio.h>
int n,cnt;
double num;
bool flag=false;
int main()
{
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%lf", &num);
		if(flag==false) //아직 안누른 상태 
			if(num!=0)
			{
				flag = true;
				if(num-(int)num!=0)
					num = (int)num+1;
			}

		cnt += (int)num;
	}
	printf("%d",cnt);
	return 0;
}