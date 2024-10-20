#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
stack<int> answer;
vector<int> visited(100000+1), previous(100000+1);
int n,k;

bool pass(int x){
    return 0<= x&&x <=100000;
}
void bfs(int start){
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(now == k) break;
        if(pass(now-1) && !visited[now-1]){
            visited[now-1] = true;
            previous[now-1] = now;
            q.push(now-1);
        }
        if(pass(now+1) && !visited[now+1]){
            visited[now+1] = true;
            previous[now+1] = now;
            q.push(now+1);
        }
        if(pass(2*now) && !visited[2*now]){
            visited[2*now] = true;
            previous[2*now] = now;
            q.push(2*now);
        }
    }

    //역추적
    for(int now = k; now!=n; now = previous[now]){
        answer.push(now);
    }
    answer.push(n);
}
int main(){
    cin>>n>>k;

    bfs(n);

    cout<<answer.size()-1<<'\n';
    while(!answer.empty()){
        cout<<answer.top()<<' ';
        answer.pop();
    }
    return 0;
}