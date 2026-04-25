#include <stdio.h>

int main(void) 
{
	int basketSize, reverseCount, first, last, temp;
	int arr[101];
	scanf("%d %d", &basketSize, &reverseCount);
	
	for (int i = 1; i <= basketSize; i++) {
		arr[i - 1] = i;
	}
	for (int i = 0; i < reverseCount; i++) {
		scanf("%d %d", &first, &last);
		for (first; first < last; first++) { 
			temp = arr[first - 1]; 
			arr[first - 1] = arr[last-1]; 
			arr[last-1] = temp; 
			last--; 
		}
	}
	for (int i = 0; i < basketSize; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}