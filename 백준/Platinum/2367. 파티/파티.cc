#include <bits/stdc++.h>
#define SIZE 305
#define SOURCE 0
#define SINK SIZE
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 1e9;

vector<int> graph[SIZE + 5];

//에드몬드_카프 - Flow 알고리즘 
int c[SIZE + 5][SIZE + 5], f[SIZE + 5][SIZE + 5], parent[SIZE + 5];
int totalFlow;
void networkFlow(int source, int sink){
	while(true){
		fill(parent, parent+SIZE+5, -1);
		queue<int> q;
		q.push(source);
		
		while(!q.empty()){
			int now = q.front();
			q.pop();

            for(int next: graph[now]){
                if(c[now][next] - f[now][next] > 0 && parent[next] == -1){
					q.push(next);
					parent[next] = now;
				}
            }
		}
		
		//sink로 가는 경로가 없으면 탈출 
		if(parent[sink] == -1) break;
		
		int amount = INF;
		for(int i=sink; i!=source; i=parent[i])
			amount = min(amount, c[parent[i]][i] - f[parent[i]][i]);
		
		for(int i=sink; i!=source; i=parent[i]){
			f[parent[i]][i] += amount;
			f[i][parent[i]] -= amount;
		}
		totalFlow += amount;
	}
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,k,d;cin>>n>>k>>d;
    //소스와 사람
    for(int i=1;i<=n;i++){
        graph[SOURCE].push_back(i);
        graph[i].push_back(SOURCE);
        c[SOURCE][i] += k;
        // c[i][SOURCE] += k;
    }

    //음식과 싱크
    for(int i=1;i<=d;i++){
        int w;cin>>w;
        int food = i + n;
        graph[food].push_back(SINK);
        graph[SINK].push_back(food);
        c[food][SINK] += w;
        // c[SINK][food] += w;
    }


    //사람과 음식
    for(int i=1;i<=n;i++){
        int m;cin>>m;
        for(int j=0;j<m;j++){
            int w;cin>>w;
            int food = w + n;
            graph[i].push_back(food);
            graph[food].push_back(i);
            c[i][food] += 1;
            // c[food][i] += 1;
        }
    }


    networkFlow(SOURCE, SINK);
    cout<<totalFlow;
    return 0;
}