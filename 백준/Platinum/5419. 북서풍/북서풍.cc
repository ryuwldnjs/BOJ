#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
using ll=long long;
struct Info{
    int x, y;
    bool operator<(const Info& other)const{
        if(x==other.x) return y < other.y;
        return x > other.x;
    }
};
struct Segtree{
    int size;
    vector<int> tree;

    Segtree(int n){
        size = (1<<(32 - __builtin_clz(n)));
        tree.resize(2 * size);
    }
    void update(int idx){
        idx += size;
        tree[idx]++;

        while(idx > 1){
            idx /= 2;
            tree[idx] = tree[2*idx] + tree[2*idx + 1];
        }
    }

    //idx이하의 모든 점 개수
    int query(int l, int r){
        int sum = 0;
        l += size;
        r += size;

        while(l <= r){
            if(l%2 == 1) sum += tree[l++];
            if(r%2 == 0) sum += tree[r--];
            l /= 2; r /= 2;
        }

        return sum;
    }
};

void compress(vector<Info>& p, vector<int> & raw_x, vector<int> &raw_y){
    sort(raw_x.begin(), raw_x.end());
    raw_x.erase(unique(raw_x.begin(), raw_x.end()), raw_x.end());
    sort(raw_y.begin(), raw_y.end());
    raw_y.erase(unique(raw_y.begin(), raw_y.end()), raw_y.end());
    
    unordered_map<int, int> mx, my;
    for(int i=0;i<raw_x.size();i++){
        mx[raw_x[i]] = i;
    }
    for(int i=0;i<raw_y.size();i++){
        my[raw_y[i]] = i;
    }

    for(int i=0;i<p.size();i++){
        p[i].x = mx[p[i].x];
        p[i].y = my[p[i].y];
    }
}
void solve(){
    int n; cin>>n;
    vector<Info> p;
    vector<int> tmp_x,tmp_y;
    for(int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        p.push_back({x,y});
        tmp_x.push_back(x);
        tmp_y.push_back(y);
    }
    compress(p, tmp_x, tmp_y);
    sort(p.begin(), p.end());

    Segtree segtree(n);
    ll answer=0;
    for(int i=0;i<n;i++){
        // int x = p[i].x;
        int y = p[i].y;
        answer += segtree.query(0,y);
        segtree.update(y);
    }
    cout<<answer<<'\n';

}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}