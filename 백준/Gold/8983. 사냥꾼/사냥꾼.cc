#include <stdio.h>
#include <algorithm>
using namespace std;
int M, N, L;
int shot[100050];// 각 사대 x 좌표
int cnt, check;
pair <int, int> animal[100050]; //동물 xy 좌표

int main()
{
	scanf("%d %d %d", &M, &N, &L);

	for (int i = 0; i < M; i++)
		scanf("%d", &shot[i]);

	for (int i = 0; i < N; i++)
		scanf("%d %d", &animal[i].first, &animal[i].second);

	sort(shot, shot + M);
//	sort(animal, animal + N);

	for (int i = 0; i < N; i++)
	{
		// i 동물 기준으로 사냥가능한 범위
		int left = animal[i].first + animal[i].second - L, right = animal[i].first - animal[i].second + L;
		
		int low = 0, high = M-1;

		if (animal[i].second > L) //y좌표가 너무 높아서 가망도 없음
			continue;
		while (low <= high) //바이너리서칭
		{
			int mid = (low + high) / 2; //중간지점 잡고
			if (left<=shot[mid] && shot[mid]<=right) //사냥 가능?
			{
				cnt++; //엌 찾음
				break;
			}
			else if (shot[mid] < left)
				low = mid + 1;
			else
				high = mid - 1;
		}
	}

	printf("%d", cnt);
	return 0;
}


