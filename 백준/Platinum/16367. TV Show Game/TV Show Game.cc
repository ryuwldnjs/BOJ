#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int id;
vector<vector<int>> graph, SCC;
vector<int> d, SCCID;
vector<bool> finished;
stack<int> s;

//tarjan
int dfs(int now){
    d[now] = ++id;
    s.push(now);

    int parent = d[now];
    for(int next: graph[now]){
        if(d[next] == 0) parent = min(parent, dfs(next));
        else if(!finished[next]) parent = min(parent, d[next]);
    }


    //각 scc의 부모들 
    if(d[now] == parent){
        vector<int> scc;
        while(true){
            int tmp = s.top();
            s.pop();
            scc.push_back(tmp);
            finished[tmp] = true;
            SCCID[tmp] = SCC.size();
            if(tmp == now) break;
        }
        SCC.push_back(scc);
    }
    return parent;
}


//R : true, B : false
//부울대수 ab + bc + ac = (a+b)(b+c)(c+a)
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int k,n; cin>>k>>n;
    graph.resize(2*k+2);
    finished.resize(2*k+2);
    d.resize(2*k+2);
    SCCID.resize(2*k+2);

    for(int i=0;i<n;i++){
        int l1,l2,l3;
        char c1,c2,c3;
        cin>>l1>>c1>>l2>>c2>>l3>>c3;
        if(c1 == 'B') l1 *= -1;
        if(c2 == 'B') l2 *= -1;
        if(c3 == 'B') l3 *= -1;

        l1 = l1<0 ? -2*l1 : 2*l1+1;
        l2 = l2<0 ? -2*l2 : 2*l2+1;
        l3 = l3<0 ? -2*l3 : 2*l3+1;

        //(a+b)는 
        //~a -> b
        //~b -> a
        graph[l1%2?l1-1:l1+1].push_back(l2);
        graph[l2%2?l2-1:l2+1].push_back(l1);

        graph[l1%2?l1-1:l1+1].push_back(l3);
        graph[l3%2?l3-1:l3+1].push_back(l1);

        graph[l3%2?l3-1:l3+1].push_back(l2);
        graph[l2%2?l2-1:l2+1].push_back(l3);
    }

    for(int i=2;i<=2*k+1;i++){
        if(!finished[i]) dfs(i);
    }

    //답 x
    for(int i=1;i<=k;i++){
        if(SCCID[i*2] == SCCID[i*2+1]){
            cout<<-1;
            return 0;
        }
    }

    
    vector<int> answer(2*k+2, -1);
    for(int i=SCC.size()-1;i>=0;i--){
        for(int j=0;j<SCC[i].size();j++){
            int t = SCC[i][j];
            if(answer[t/2] == -1) answer[t/2] = (t%2)^1;
        }
    }

    for(int i=1;i<=k;i++){
        cout<<(answer[i] ? 'R' : 'B');
    }
    return 0;
}