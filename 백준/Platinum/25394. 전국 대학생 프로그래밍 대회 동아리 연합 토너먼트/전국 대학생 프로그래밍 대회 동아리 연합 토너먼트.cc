#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n;
vector<vector<int>> graph;
vector<int> subtree;//i가 루트일때 서브트리의 노드 개수
// vector<int> sub_xor;

int dfs(int now){
    if(subtree[now] != 0) return subtree[now];

    subtree[now] = 1;

    for(int next: graph[now]){
        int cnt = dfs(next);
        subtree[now] += cnt;
        // sub_xor[now] ^= cnt;
    }
    return subtree[now];
}


int root,other;
vector<pii> answer;
void find(int now){
    set<int> seen;
    for(int next: graph[now]){
        seen.insert(subtree[next]);
    }

    int needed = 1;
    for(int i=1;i<subtree[now] + subtree[other]; i*=2){
        if(seen.count(i) == 1) needed = i*2;
        else break;
    }

    bool isNotFound = true;
    for(int next: graph[now]){
        if(subtree[next] + subtree[other] == needed){
            find(next);
            isNotFound = false;
        }
    }
    // printf("\n");

    //더이상 자식으로내려갈수없으면, 현재 노드에 달아야함
    if(isNotFound){
        answer.push_back({now, other});
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int origin_n; cin>>origin_n; 
    n = 1<<origin_n;

    graph.resize(n+1);
    subtree.resize(n+1);
    // sub_xor.resize(n+1);

    vector<int> indegree(n+1);
    vector<int> win(n+1), lose(n+1);
    for(int i=0;i<n-2;i++){
        int a,b;cin>>a>>b;
        win[a]++; lose[b]++;
        graph[a].push_back(b);
        indegree[b]++;
    }
    root = -1;
    other = -1;

    for(int i=1;i<=n;i++){
        if(win[i] == origin_n){
            root = i;
        }
    }
    if(root == -1){
        for(int i=1;i<=n;i++){
            if(win[i] == origin_n-1 && lose[i] == 0){
                root = i;
            }
        }
    }



    vector<int> start;
    for(int i=1;i<=n;i++){
        if(indegree[i] == 0){
            dfs(i);
            start.push_back(i);
        }
    }
    
    if(start[0] == root) other = start[1];
    else other = start[0];

    //결승전이 날아간거임
    if(subtree[root] == subtree[other]){
        if(root > other) swap(root, other);
        cout<<root<<' '<<other<<'\n';
        cout<<other<<' '<<root<<'\n';
        return 0;
    }


    find(root);

    sort(answer.begin(), answer.end());

    for(pii p: answer){
        cout<<p.first<<' '<<p.second<<'\n';
    }
    return 0;
}