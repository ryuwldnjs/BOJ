#include <stdio.h>
#include <vector>
#include <queue>
#define INF 123456789
using namespace std;
int v,e,k; //정점갯수 ,간선 갯수, 시작 점 
int from, to, cost; //from에서 to로 가중치는 cost 
vector<vector<pair<int,int> > > a; //간선정보 
priority_queue<pair<int, int> > pq;//우선순위 큐 
int dist[20000+50];

void dijkstra(int start)
{
	for(int i=1;i<=v;i++) //초기거리 무한대 설정 
		dist[i]=INF;
		
		
	dist[start]=0; 
	pq.push({ -dist[start], start });
	
	while(!pq.empty()) //큐가 빌때까지
	{

		int distance = -pq.top() .first; //거리는 음수로 저장 
 		int current = pq.top().second;
		pq.pop(); //팝!
		
		if(dist[current] < distance) //이미 더 짧은 경로일경우 
			continue; 
		
		
		for(int i=0; i<a[current].size() ; i++) //current에서 연결된 정점들 체크 
		{
			int next = a[current][i].first; //다음타겟 current에서 i로 가는 경로 
			int next_distance = distance + a[current][i].second; //다음 타겟의 가중치 
			
			if(next_distance <dist[next])
			{
				dist[next] = next_distance; 
				pq.push({-next_distance, next});
			}
		 }
		 
		  
	 } 
}


int main()
{
	scanf("%d %d %d", &v,&e, &k);
	a.resize(v+1);
	for(int i=1;i<=e;i++)
	{
		scanf("%d %d %d", &from,&to,&cost);
		a[from].push_back({to,cost});
	 } 
	 dijkstra(k);
	// printf("다익스트라 탈출!!!!");
	
	
	 for(int i=1;i<=v;i++)
	 {
	 	if(dist[i]!=INF)
	 		printf("%d\n", dist[i]);
	 	else
	 		printf("INF\n");
	 }
	return 0;
}