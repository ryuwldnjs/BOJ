#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct SegTree{
    vector<int> tree;
    int size;
    SegTree(int n){
        size = 1<<(32 - __builtin_clz(n));
        tree.resize(size * 2);
        build(n);
    }

    void build(int n){
        for(int i=1;i<=n;i++){
            tree[i + size] = 1;
        }

        for(int i=size-1; i>=1; i--){
            tree[i] = tree[i*2] + tree[i*2 + 1];
        }
    }

    void update(int idx){
        idx += size;
        tree[idx] = 0;
        while(idx > 1){
            idx /= 2;
            tree[idx] = tree[idx*2] + tree[idx*2+1];
        }
    }

    //k번째 수
    int query(int k){
        int idx = 1;
        while(idx < size){
            if(tree[idx*2] >= k) idx = idx*2;
            else{
                k -= tree[idx*2];
                idx = idx*2 + 1;
            }
        }

        update(idx - size);
        return idx - size;
    }
};

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,k;cin>>n>>k;
    SegTree segtree(n);

    int prev = 1;
    vector<int> answer;
    //(prev + k -1 -1) % remain + 1
    for(int remain = n; remain > 0; remain--){
        int target = (prev + k - 2) % remain + 1;
        prev = target;
        answer.push_back(segtree.query(target));
    }

    for(int i=0;i<n;i++){
        cout<<(i==0 ? "<" : " ");
        cout<<answer[i];
        cout<<(i==n-1 ? ">" : ",");

    }
    return 0;
}