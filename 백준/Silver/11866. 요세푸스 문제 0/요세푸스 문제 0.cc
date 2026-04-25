#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<int> q;
vector<int> vec;
int n,k;
int idx=1;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) q.push(i);
	
	while(!q.empty()){
		if(idx++ % k) q.push(q.front());
		else vec.push_back(q.front());
		q.pop();
	}
	printf("<%d",vec[0]);
	for(int i=1;i<vec.size(); i++) printf(", %d", vec[i]);
	printf(">");
	return 0;
}