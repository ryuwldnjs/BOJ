#include <stdio.h>
#include <algorithm>
using namespace std;
int card[21];

int main()
{
	int a, b;
	for (int i = 0; i < 21; i++)
		card[i] = i;

	for (int i = 0; i < 10; i++)
	{
		scanf("%d %d", &a, &b);

		for (int i = 0; i <= (b-a)/2; i++)
		swap(card[a + i], card[b - i]);
	}


	for (int i = 1; i <= 20; i++)
		printf("%d ", card[i]);
	return 0;
}

