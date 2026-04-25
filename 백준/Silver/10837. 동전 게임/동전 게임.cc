#include <stdio.h>
int K, C;//라운드 수. 입력개수
int M, N;
int main()
{
	scanf("%d %d", &K, &C);
	for(int i=0;i<C;i++)
	{
		scanf("%d %d", &M, &N);
		if(M<=N&&N>M+(K-M+1)/2 || M>N&& M > N+ (K-N)/2+1)
		printf("0\n");
		else
		printf("1\n");
	}
	return 0;
}