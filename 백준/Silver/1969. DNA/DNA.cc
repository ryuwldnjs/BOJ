#include <stdio.h>
#include <vector>
using namespace std;
vector<char> vec; 
int n,m,cnt;
char ch;
int arr[55][4]; //n, 단 사전식으로 배열 
int retr(char ch)
{
	if(ch=='A') return 0;
	if(ch=='T') return 3;
	if(ch=='G') return 2;
	if(ch=='C') return 1;	
}
char retr2(int num)
{
	if(num==0) return 'A';
	if(num==1) return 'C';
	if(num==2) return 'G';
	if(num==3) return 'T';
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf(" %c", &ch);
			arr[j][retr(ch)]++;
		}
	}
	for(int i=0;i<m;i++)
	{
		int max=0, check=0;
		for(int j=0;j<4;j++)
		{
			if(arr[i][j]>max)
			{
				max=arr[i][j];
				check=j;
			} 
		}
		vec.push_back(retr2(check));
		cnt+= n-max;
	}
	for (int i = 0; i < vec.size(); i++)
		printf("%c",vec[i]);
		
	printf("\n%d",cnt);
	return 0;
}