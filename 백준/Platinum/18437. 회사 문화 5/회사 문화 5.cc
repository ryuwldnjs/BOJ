#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

//비재귀 Lazy세그
struct SegTree{
    
    vector<ll> tree, lazy;
    int size, height;

    void build(vector<ll> &arr){
        int n = arr.size();
        size = 1<<(32 - __builtin_clz(n));
        height = 32 - __builtin_clz(n);
        
        tree = vector<ll>(size*2, 0);
        lazy = vector<ll>(size*2, -1);

        for(int i=0;i<n;i++){
            tree[size+i] = arr[i];
        }
        for(int i=size-1;i>=1;i--){
            tree[i] = tree[i*2] + tree[i*2+1];
        }
    }

    void apply(int idx, ll val, int len){
        tree[idx] = val * len;
        lazy[idx] = val;
    }

    void push(int idx){
        for(int h=height; h>0; h--){
            int i = idx>>h;
            if(lazy[i] != -1){
                ll val = lazy[i];
                int len = 1<<(h-1);
                apply(i*2, val, len);
                apply(i*2+1, val, len);
                lazy[i] = -1;
            }
        }
    }

    void pull(int idx){

        while(idx > 1){
            idx/=2;

            if(lazy[idx] == -1)  tree[idx] = tree[idx*2] + tree[idx*2+1];
            // int h = log2(idx);
            // if(idx < size && lazy[idx] != -1){
            //     tree[idx] = lazy[idx] * ((size >> h));
            //     lazy[idx] = -1;
            // }
        }
    }


    void update(int l, int r, int val){
        if(l > r) return;
        l += size; r += size;
        int l0 = l, r0 = r;

        push(l0); push(r0);

        int len = 1;
        while(l <= r){
            if(l%2 == 1) apply(l++, val, len);
            if(r%2 == 0) apply(r--, val, len);

            l/=2; r/=2; len*=2;
        }

        pull(l0); pull(r0);
    }

    ll query(int l ,int r){
        if(l > r) return 0;
        l += size; r += size;
        push(l); push(r);

        ll ret = 0;
        while(l <= r){
            if(l%2 == 1) ret += tree[l++];
            if(r%2 == 0) ret += tree[r--];
            
            l/=2; r/=2;
        }
        return ret;
    }

};


vector<int> graph[100000+5];

//ETT
vector<ll> arr;//arr[i] = 컴퓨터 켜져있는지 on off
bool visited[100000+5];
ll pos[100000+5], children[100000+5];

int preorder(int now){
    visited[now] = true;
    pos[now] = arr.size();
    arr.push_back(1); //초기엔 전부 켜져(1)있음

    for(int next: graph[now]){
        if(visited[next]) continue;
        children[now] += preorder(next);
    }
    children[now] += graph[now].size();

    return children[now];
}

SegTree segtree;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int parent; cin>>parent;
        graph[parent].push_back(i);
    }
    preorder(1);

    segtree.build(arr);

    int m;cin>>m;
    while(m--){
        int com,idx;cin>>com>>idx;
        int l = pos[idx] + 1; //idx자기자신은 제외
        int r = pos[idx] + children[idx];
        
        if(com == 1) segtree.update(l, r, 1);
        else if(com == 2) segtree.update(l, r, 0);
        else if(com == 3) cout<<segtree.query(l, r)<<'\n';
    }
    return 0;
}