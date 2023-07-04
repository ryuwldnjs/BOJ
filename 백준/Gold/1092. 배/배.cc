#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

queue<int> q[50];
int n,m,crane[55], box,time;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>crane[i];
	sort(crane, crane+n);
	
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>box;
		if(box > crane[n-1]){
			time = -1;
			goto ulsan;
		}
		
		for(int j=0;j<n;j++){
			if(box <= crane[j]){
				q[j].push(box);
				break;
			}
		}
	}
	
	while(true){
		int remain=0;
		for(int i=0;i<n;i++)
			remain += q[i].size();
		if(!remain) break;
		
		
		for(int i=0;i<n;i++){//i번째 크레인 업무 배정 
			for(int j=i;j>=0;j--){//i구간의 무게를 가진 박스 
				if(!q[j].empty()){
					q[j].pop();
					break;//일감 하나 물었으면 됐음 
				}
			}
			
		}
		time++;
	}
	
	ulsan:;
	cout<<time;
	return 0;
}