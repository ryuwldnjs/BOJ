#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const ll MOD = 1000000007;

struct MergeTree{
    vector<vector<int>> tree;
    int size;

    MergeTree(int n){
        size = 1<<(32 - __builtin_clz(n));
        tree.resize(size*2);
    }

    void build(vector<int> &arr){
        for(int i=0;i<arr.size();i++){
            tree[size + i].push_back(arr[i]);
        }

        for(int i=size-1; i>=1;i--){
            tree[i].resize(tree[i*2].size() + tree[i*2+1].size());
            merge(tree[i*2].begin(), tree[i*2].end(), tree[i*2+1].begin(), tree[i*2+1].end(), tree[i].begin());
        }
    }


    //[l,r]구간에서 c이하의 개수
    int query(int l, int r, int c){
        int ret = 0;
        l += size;
        r += size;
                
        while(l <= r){
            if(l%2==1){
                ret += lower_bound(tree[l].begin(), tree[l].end(), c+1) - tree[l].begin();
                l++;
            }
            if(r%2==0){
                ret += lower_bound(tree[r].begin(), tree[r].end(), c+1) - tree[r].begin();
                r--;
            }

            l /= 2; r /= 2;
        }
        return ret;
    }
};


vector<vector<int>> graph;
vector<int> color; //기존 배열
vector<int> arr; //새로운 배열

int subtree[200000 + 5];//i번노드가 루트일때의 본인제외 서브트리 크기
int pos[200000 + 5]; //i번 노드의 위치
//오일러투어 테크닉
vector<bool> visited;
int preorder(int now){
    // printf("%d방문\n", now);
    visited[now] = true;
    pos[now] = arr.size();
    arr.push_back(color[now]);

    for(int next : graph[now]){
        // printf("%d: %d\n", now, next);
        if(visited[next]) continue;
        subtree[now] += preorder(next);
    }
    subtree[now] += graph[now].size();
    if(now != 1) subtree[now]--; //부모 노드가 있으면 제외

    // printf("%d: %d\n", now, subtree[now]);
    // cout<<now<<' '<<subtree[now]<<'\n';
    // printf("%d: %d %d\n", now, pos[now], subtree[now]);
    return subtree[now];
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,m,c;cin>>n>>m>>c;
    color.resize(n+1);
    graph.resize(n+1);
    visited.resize(n+1);

    for(int i=1;i<=n;i++) cin>>color[i];

    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    preorder(1);

    MergeTree mergetree(n);
    mergetree.build(arr);
    

    ll answer = 0;
    while(m--){
        int v,c;cin>>v>>c;
        answer += mergetree.query(pos[v], pos[v] + subtree[v], c);
        answer %= MOD;
        // printf("%d,%d\n", pos[v], pos[v]+subtree[v]);
        // cout<<mergetree.query(pos[v], pos[v] + subtree[v], c)<<'\n';
    }
    
    cout<<answer;
    return 0;
}