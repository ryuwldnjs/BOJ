#include <iostream>
#include <queue> 
#define INF 1000000000
using namespace std;
int n,m,a,b,dist[20005];
vector<vector<pair<int ,int> > > edge;//간선정보 
priority_queue<pair<int ,int> > pq; 
int ans,maximum=-123456789,cnt;
int current;

void dijkstra(int start)
{
	for(int i=1;i<=n;i++) //초기거리 무한대 설정 
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
		
		
		for(int i=0; i<edge[current].size() ; i++) //current에서 연결된 정점들 체크 
		{
			int next = edge[current][i].first; //다음타겟 current에서 i로 가는 경로 
			int next_distance = distance + edge[current][i].second; //다음 타겟의 가중치 
			
			if(next_distance <dist[next])
			{
				dist[next] = next_distance; 
				pq.push({-next_distance, next});
			}
		 }
		 
		  
	 } 
}


int main(){
	cin>>n>>m;
	//플로이드 거리 무한대 설정 
	edge.resize(n+1);
	
	for(int i=0;i<m;i++){ //직접연결된 간선 
		cin>>a>>b;
		edge[a].push_back({b,1});
		edge[b].push_back({a,1});
	}
	dijkstra(1);
	
//	for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
	
	for(int i=2;i<=n;i++){
		if(dist[i] > maximum){
			cnt=0;
			maximum = dist[i];
			ans = i;
		}
		if(dist[i]==maximum) cnt++;
	}
	
	cout<<ans<<" "<<maximum<<" "<<cnt;
	return 0;
}