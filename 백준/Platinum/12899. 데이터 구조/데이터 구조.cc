#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int SIZE = 2000000+10;
struct SegTree{
    vector<int> tree;
    int size;
    SegTree(int n){
        size = 1<<(32 - __builtin_clz(n));
        tree.resize(size * 2);
    }

    void update(int idx, int diff){
        idx += size;
        tree[idx] += diff;
        while(idx > 1){
            idx /= 2;
            tree[idx] = tree[idx*2] + tree[idx*2 + 1];
        }
    }

    //k번째 수
    int query(int k){
        int idx = 1;
        while(idx < size){
            if(tree[idx*2] >= k) idx = idx * 2;
            else{
                k -= tree[idx*2];
                idx = idx * 2 + 1;
            }
        }
        update(idx - size, -1);
        return idx - size;
    }

};

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    SegTree segtree(SIZE);
    while(n--){
        int a,b;cin>>a>>b;
        if(a == 1) segtree.update(b, 1);
        else cout<<segtree.query(b)<<'\n';
    }
    return 0;
}