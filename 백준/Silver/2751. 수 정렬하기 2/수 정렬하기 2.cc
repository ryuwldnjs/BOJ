#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[1000000+5];
int n;
int main()
{
	scanf("%d", &n);
	for(int i =0;i<n;i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr, arr+n);
	
	for(int i=0;i<n;i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}