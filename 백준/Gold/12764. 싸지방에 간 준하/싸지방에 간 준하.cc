#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int,int>;
//가독성 ㅋㅋ 
priority_queue<int, vector<int>, greater<int>> remain;
priority_queue<pii, vector<pii>, greater<pii>> occupied;  
vector<pair<int,int>> vec;
int cnt[100000+10];
int n,a,b;
int MAX = -1;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) remain.push(i);//싸지방 자리번호 넣기 
	
	for(int i=0;i<n;i++){
		cin>>a>>b;
		vec.push_back({a, b});
	}
	sort(vec.begin(), vec.end()); //시작시간 기준 정렬
	
	//occupied는 {end, 좌석번호}로 넣음 
	
	for(int i=0;i<n;i++){
		//사용중이던 자리 확인하기
		//i번쨰 사람이 왔을때, 이미 떠난사람이면 정리하기 
	/*	if(occupied.empty()) {//모든 자리가 남았을때 
			occupied.push({vec[i].second, remain.top()});
			remain.pop();
		}*/
		//자리 반납 시스템 
		while(!occupied.empty() && vec[i].first > occupied.top().first){
			//int idx = occupied.top().second;
			remain.push(occupied.top().second);//자리 반납 
			occupied.pop();
			//occupied.push({vec[i].end, idx});
		}
		int num = remain.top(); //남은 자리중 제일 낮은 번호
		remain.pop();//해당 번호 사용시작 
		
		occupied.push({vec[i].second, num});
		cnt[num]++;//해당번호 누적 사용자 수 기록 
		
		MAX = max(MAX, num);//최대 번호 기록 
		
	} 
	cout<<MAX<<'\n';
	for(int i=1;i<=MAX;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}