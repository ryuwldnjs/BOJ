#include <stdio.h>
#include <algorithm>
using namespace std;
int a, b; //최대공약수 최소공배수 
int x, y; // 구하고싶은 두 수
int tmp;
int gcd(int a, int b) {
 	if (a == 0)
 		return b;
 	return gcd(b%a, a);

}

int main()
{
	scanf("%d %d", &a, &b);
	tmp = b / a; 

	for (int i = 1; i*i <= tmp; i++)
	{
		if (tmp % i == 0 && gcd(i, tmp/i)==1) //tmp가 i의 배수일때 (i * tmp/i) 가능
		{
			x = i;
			y = tmp / i;
		}
	}
    
	// 작은거 먼저 출력
	if (x > y)
		swap(x, y);
	printf("%d %d", a*x, a*y);
	return 0;
}

