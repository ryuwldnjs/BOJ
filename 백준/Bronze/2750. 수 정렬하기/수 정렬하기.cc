#include <iostream>
#include <cstdlib>
using namespace std;

void insertionSort(int* arr, int n){
	for(int j=1; j<n; j++){
		int key = arr[j];
		
		int i = j-1;
		while(i>=0 && arr[i] > key){
			arr[i+1] = arr[i];
			i--;
		}
		arr[i+1] = key;
	}
}


int main(){
	int arr[1005], n;
	scanf("%d", &n);
	for(int i=0;i<n;i++) scanf("%d", &arr[i]);
	
	insertionSort(arr, n);
	
	for(int i=0;i<n;i++) printf("%d\n", arr[i]);
	return 0;
}