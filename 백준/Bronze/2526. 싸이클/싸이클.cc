#include <stdio.h>
#include <vector>
using namespace std;

vector<int> vec;
int main()
{
	int n, p;
	int k;
	int ans, flag=0;
	scanf("%d %d", &n, &p);
	vec.push_back(n);
	k = n;
	while (true)
	{
		k = k*n%p;
		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i] == k)//중복되는거 찾을때
			{
				ans = i;
				flag = 1;
				break;
			}
		}
		if (flag == 1) //중복되는거 찾았으면
			break;
		vec.push_back(k);
	}
	ans = vec.size() - ans;
	printf("%d", ans);
	return 0;
}

