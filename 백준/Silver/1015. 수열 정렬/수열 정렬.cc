#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
bool visited[55];
vector<int> a,b;
//2 3 1
//1 2 3
int main(){
	cin>>n;
	a.resize(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	b = a;
	sort(b.begin(), b.end());
	
	for(int i=0;i<n;i++){
		int target = a[i];
		for(int j=0;j<n; j++){
			if(visited[j]) continue;
			if(b[j] == target){
				visited[j] = true;
				cout<<j<<' ';
				break;
			}
		}
	}
	return 0;
}