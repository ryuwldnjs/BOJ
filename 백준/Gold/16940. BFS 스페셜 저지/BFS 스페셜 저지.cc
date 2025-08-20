#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n;
set<int> graph[100000+5];

bool isValid(){
    queue<int> q;
    q.push(0);

    for(int i=0;i<n;){
        int now = q.front();
        q.pop();

        int sz = graph[now].size();
        if(i > 0) sz--; // 부모노드 제외
       
        while(sz--){
            int x;cin>>x;
            if(graph[now].count(x)==0) return false;

            q.push(x);
            i++;
        }
        
    }
    return true;
}


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;

    graph[0].insert(1);
    graph[1].insert(0);

    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    

    cout<<isValid();
    return 0;
}