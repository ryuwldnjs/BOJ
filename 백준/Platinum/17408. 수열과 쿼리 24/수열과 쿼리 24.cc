#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct SegTree{
    int size;
    vector<pii> tree;

    SegTree(int n){
        size = 1<<(32 - __builtin_clz(n));
        tree.resize(size*2, {-1, -1});
    }

    void build(vector<int> &arr){
        for(int i=0;i<arr.size();i++){
            tree[i + size] = {arr[i], -1};
        }

        for(int i=size-1;i>=1;i--){
            vector<int> partial = {tree[i*2].first, tree[i*2].second, tree[i*2 + 1].first, tree[i*2 + 1].second};
            sort(partial.begin(), partial.end(), greater<int>());
            tree[i] = {partial[0], partial[1]};
        }
    }

    void update(int idx, int val){
        idx += size;
        tree[idx] = {val, -1};
        while(idx > 1){
            idx /= 2;
            vector<int> partial = {tree[idx*2].first, tree[idx*2].second, tree[idx*2 + 1].first, tree[idx*2 + 1].second};
            sort(partial.begin(), partial.end(), greater<int>());
            tree[idx] = {partial[0], partial[1]};
        }
    }

    int query(int l, int r){
        l += size; r += size;
        vector<int> partial;
        while(l <= r){
            if(l%2 == 1){
                partial.push_back(tree[l].first); partial.push_back(tree[l].second);
                l++;
            }
            if(r%2 == 0){
                partial.push_back(tree[r].first); partial.push_back(tree[r].second);
                r--;
            }
            l /= 2; r /= 2;
        }
        sort(partial.begin(), partial.end(), greater<int>());
        int ret = partial[0] + partial[1];
        return ret;
    }
};

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    vector<int> a(n+1);
    SegTree segtree(n+1);
    
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    segtree.build(a);

    int m;cin>>m;
    while(m--){
        int a,b,c;cin>>a>>b>>c;
        if(a == 1){
            segtree.update(b, c);
        }
        else{
            cout<<segtree.query(b, c)<<'\n';
        }
    }
    return 0;
}