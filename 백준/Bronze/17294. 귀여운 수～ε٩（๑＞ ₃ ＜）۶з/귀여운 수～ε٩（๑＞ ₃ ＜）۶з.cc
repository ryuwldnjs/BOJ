#include <stdio.h>
#include <string.h>
char str[22];
bool flag = true; 
int main()
{
	scanf("%s", str);
	int len = strlen(str);
	
	if(len>=3)
	{
		int gap = str[1]-str[0];
		for(int i=1;str[i]!=0;i++)
		{
			if (gap != str[i]-str[i-1])
			{
				flag= false;
				break;
			}
		}
	}
	
	if(flag)
		printf("◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!");
	else
		printf("흥칫뿡!! <(￣ ﹌ ￣)>");
	return 0;
}