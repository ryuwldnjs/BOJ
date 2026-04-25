#include <iostream>
#include <queue>
using namespace std;
priority_queue<int> max_pq;
priority_queue<int, vector<int>,greater<int> > min_pq;
int N, num;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>N;
	
	for(int i=0;i<N;i++){
		cin>>num;
		if(i%2==0){
			max_pq.push(num);
			
			if(!min_pq.empty()){//아마도 3번째 시행부터 
				int tmp1 = max_pq.top();//작은숫자들의 집합중 
				int tmp2 = min_pq.top();//큰 숫자들의 집합중 
				if(tmp1 > tmp2){//규칙에 어긋,swap
					max_pq.pop(), min_pq.pop();
					max_pq.push(tmp2), min_pq.push(tmp1);
				}
			}
		}
		else{ //큰 숫자들 집단에넣을차례 
			min_pq.push(num);
			int tmp1 = max_pq.top();//작은숫자들의 집합중 
			int tmp2 = min_pq.top();//큰 숫자들의 집합중 
			if(tmp1 > tmp2){//규칙에 어긋,swap
				max_pq.pop(), min_pq.pop();
				max_pq.push(tmp2), min_pq.push(tmp1);
			
			}
		}
		
		cout<<max_pq.top()<<'\n';
	}
	return 0;
}