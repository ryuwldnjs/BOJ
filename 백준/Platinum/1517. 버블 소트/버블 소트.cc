#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct SegTree{
    vector<ll> tree;
    int size;
    SegTree(int n){
        size = 1<<(32 - __builtin_clz(n));
        tree.resize(2 * size);
    }
    void update(int idx){
        idx += size;
        tree[idx]++;
        while(idx > 1){
            idx /= 2;
            tree[idx] = tree[2*idx] + tree[2*idx+1];
        }
    }

    //idx값보다 작은 값들의 개
    ll query(int idx){
        int l = size;
        int r = size + idx - 1;
        ll ret = 0;
        while(l<=r){
            if(l%2 == 1) ret += tree[l++];
            if(r%2 == 0) ret += tree[r--];
            l /= 2; r /= 2;
        }
        return ret;
    }
};

void compress(vector<int> &arr){
    unordered_map<int, int> m;
    vector<int> tmp = arr;
    sort(tmp.begin(), tmp.end());
    int val = 0;
    for(int i=0;i<tmp.size();i++){
        if(!m.count(tmp[i])) m[tmp[i]] = val++;
    }

    for(int i=0;i<arr.size();i++){
        arr[i] = m[arr[i]];
    }
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    compress(a);

    SegTree segtree(n);
    ll answer = 0;
    for(int i=n-1;i>=0;i--){
        answer += segtree.query(a[i]);
        segtree.update(a[i]);
    }
    cout<<answer;
    return 0;
}