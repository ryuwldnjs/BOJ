#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
int t,start,endd,ans;
bool not_prime[10005]; // true일경우 소수x 
bool visited[10005];//숫자 방문 
int number[4]; //4자리 숫자 

int main(){
	for(int i=2;i<10005;i++){
		if(not_prime[i]) continue;
		for(int j=i+i;j<10005;j+=i){
			not_prime[j]=true;
		}
	}
	
	scanf("%d", &t);
	while(t--){	
		bool flag=false;
		memset(visited,false, 10005);
		queue<pair<int,int> > q;
		
		scanf("%d %d", &start, &endd);
		
		q.push({start,0});
		visited[start]=true;
		
		
		while(!q.empty()){
			int now = q.front().first; //숫자 
		//	printf("%d, ", now);
			int dist = q.front().second;//바꾼횟수 
			if(now == endd) //목표 도달
			{
				ans = dist;
				flag=true;
				break; 
				
			 } 
			q.pop();
			
			for(int i=0;now!=0;i++){ //네자리숫자를 배열에 보관 
				number[i]=now%10;
				now/=10;
			}
			
			
			for(int i=0;i<4;i++){ //각 자리 
				for(int j=0;j<10;j++){ //숫자 바꾸기 
					int tmp = number[i];
					if(i!=3 || j!=0) number[i]=j;//첫째자리는 0이 되어선 안됨 
					int next_num = number[0]+10*number[1]+100*number[2]+1000*number[3];
					
					if(visited[next_num]==false && not_prime[next_num]==false){//방문하지않았고, 소수일경우 
						q.push({next_num, dist+1});
						visited[next_num]=true;
					}
					number[i]=tmp;//다시 숫자 원상 복귀 
				}

			}
		}
		
		if(flag) printf("%d\n", ans);
		else	printf("IMPOSSIBBLE\n");
	}
	return 0;
}