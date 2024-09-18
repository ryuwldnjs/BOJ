#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;
#define INF 1e9

struct Info{
    string arr;
    int distance;

    const bool operator<(const Info& other)const{
        return distance > other.distance;
    }
};
struct Command{
    int a,b,cost;
};

int n,m;
string arr, goal;
vector<Command> cmds;
unordered_map<string, int> dist;
priority_queue<Info> pq;

void init(string arr){
    sort(arr.begin(), arr.end());
    goal = arr;
    do{
        dist[arr] = INF;
    }while(next_permutation(arr.begin(), arr.end()));
}

void dijkstra(string start){
    dist[start] = 0;
    pq.push({start, 0});

    while(!pq.empty()){
        string now = pq.top().arr;
        int distance = pq.top().distance;
        pq.pop();

        if(dist[now] < distance) continue;

        for(auto cmd : cmds){
            string next = now;
            int a = cmd.a - 1; //인덱스 보정
            int b = cmd.b - 1;
            swap(next[a], next[b]);
            int next_distance = distance + cmd.cost;
            
            if(next_distance < dist[next]){
                dist[next] = next_distance;
                pq.push({next, next_distance});
            }

        }
    }
    
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        x--; //[1,10] -> [0,9]
        arr += to_string(x);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int a,b,c; cin>>a>>b>>c;
        cmds.push_back({a,b,c});
    }
    init(arr);
    dijkstra(arr);
    cout<<(dist[goal]==INF ? -1 : dist[goal]);
    return 0;
}