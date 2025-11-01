#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct SegTree{
    vector<int> tree;
    int size;

    void build(int n){
        size = 1<<(32 - __builtin_clz(n));
        tree.resize(size*2);

        for(int i=0;i<n;i++) tree[i + size] = 1;
        for(int i=size-1;i>=1;i--){
            tree[i] = tree[i*2] + tree[i*2+1];
        }
    }

    void update(int idx, int val){
        idx += size;
        tree[idx] = val;
        while(idx > 1){
            idx /= 2;
            tree[idx] = tree[idx*2] + tree[idx*2+1];
        }
    }

    //k번째 1의 인덱스 반환
    int query(int k){
        int idx = 1;

        while(idx < size){
            if(tree[idx*2] < k){
                k -= tree[idx*2];
                idx = idx*2+1;
            }
            else{
                idx = idx*2;
            }
        }

        return idx - size;
    }
};

SegTree segtree;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    segtree.build(n);

    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];

    vector<int> answer(n);
    for(int i=n;i>0;i--){
        int idx = segtree.query(i - a[i]);
        answer[idx] = i;
        segtree.update(idx, 0);
    }

    for(int i=0;i<n;i++) cout<<answer[i]<<' ';
    return 0;
}