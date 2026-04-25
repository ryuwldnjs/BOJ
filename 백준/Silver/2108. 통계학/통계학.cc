#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 1234567890
using namespace std;

int arr[500000+50];
pair<int,int> cnt[8000+5];

int n;
double a;
bool compare(const pair<int,int> &a, const pair<int,int> &b){
	if(a.first == b.first)
		return a.second < b.second; //인덱스는 오름차순 
	return a.first > b.first; //내림차순 
}

int main(){
	scanf("%d", &n);
	for(int i=0;i<=8000;i++) {cnt[i] = {-INF, i-4000};};
	
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
		if(cnt[arr[i]+4000].first == -INF) cnt[arr[i]+4000].first = 0;
		cnt[arr[i]+4000].first++;
		a += arr[i];
	}
	
	sort(arr, arr+n);
	
	a /= n;
	int b = arr[n/2];
	
	
	sort(cnt, cnt+8001, compare);
	

	int c = cnt[0].first==cnt[1].first ? cnt[1].second : cnt[0].second;
	
	int d = arr[n-1] - arr[0];
	
	
	printf("%d\n%d\n%d\n%d", (int)round(a),b,c,d);
	return 0;
}