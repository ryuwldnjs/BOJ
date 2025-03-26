#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;
struct Info{
    int com, k, i,j;
    int check_idx;//초기 순서로 다시 되돌리기 위함
    //오프라인 쿼리 순서 재조정
    bool operator<(const Info& other)const{
        if(k == other.k) return com < other.com;
        return k < other.k;
    }
};
struct Segtree{
    int size;
    vector<ll> tree;
    Segtree(int n){
        size = 1<<(32 - __builtin_clz(n));
        tree.resize(2 * size);
    }

    void build(vector<ll> & arr){
        for(int i=0;i<arr.size();i++){
            tree[size + i] = arr[i];
        }

        for(int i= size-1;i>0;i--){
            tree[i] = tree[2*i] + tree[2*i+1];
        }
    }

    void update(int idx, ll val){
        idx += size;
        tree[idx] = val;

        while(idx>0){
            idx /= 2;
            tree[idx] = tree[2*idx] + tree[2*idx+1];
        }
    }

    ll query(int l, int r){
        l += size;
        r += size;
        ll sum=0;

        while(l<=r){
            if(l%2==1) sum += tree[l++];
            if(r%2==0) sum += tree[r--];
            l/=2; r/=2;
        }
        return sum;
    }
};
vector<ll> arr;
vector<Info> query;//쿼리 순서 재조정
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n; cin>>n;
    arr.resize(n);
    Segtree segtree(n);
    for(ll &i: arr) cin>>i;
    segtree.build(arr);
    int m; cin>>m;
    
    //오프라인쿼리 재구성
    int k=1;
    for(int i=1;i<=m;i++){
        int a,b,c,d; cin>>a;
        if(a==1){
            cin>>c>>d;
            b = k++;//k번째 쿼리인지 저장
            c--;
        }
        else{
            cin>>b>>c>>d;
            c--; d--;
        }
        query.push_back({a,b,c,d, i});
    }
    sort(query.begin(), query.end());



    vector<pair<int,ll>> answer;
    for(Info q: query){
        if(q.com == 1) segtree.update(q.i, q.j);
        else answer.push_back({q.check_idx, segtree.query(q.i, q.j)});
    }
    sort(answer.begin(), answer.end());
    for(int i=0;i<answer.size();i++) cout<<answer[i].second<<'\n';
    return 0;
}