#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 2e9;
struct Info{
    int idx;
    int val;
    int l=-INF;
    int r=INF;

    bool operator<(const Info& other)const{
        return val < other.val;
    }
    bool operator<(const int val)const{
        return this->val <val;
    }
};

vector<Info> level[200005];
vector<pii> tree(200005, {-1,-1});

int traverse(int now){
    int ret = 1;
    if(tree[now].first != -1) ret += traverse(tree[now].first);
    if(tree[now].second != -1) ret += traverse(tree[now].second);
    return ret;
}

bool makeTree(int h){
    int p_idx = 0;
    int c_idx = 0;

    while(p_idx < level[h-1].size() && c_idx < level[h].size()){
        Info &parent = level[h-1][p_idx];
        Info &child = level[h][c_idx];
        
        //부모의 왼쪽 자식으로 할당
        if(child.val < parent.val && child.val >= parent.l && tree[parent.idx].first == -1){
            tree[parent.idx].first = child.idx;
            child.l = parent.l;
            child.r = parent.val - 1;
            c_idx++;
        }
        //부모의 오른쪽 자식으로 할당
        else if(child.val > parent.val && child.val <= parent.r && tree[parent.idx].second == -1){
            tree[parent.idx].second = child.idx;
            child.l = parent.val + 1;
            child.r = parent.r;
            c_idx++;
        }
        else p_idx++;
        // if(tree[parent.idx].first != -1 && tree[parent.idx].second != -1) p_idx++;
    }
    return true;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int val,h;cin>>val>>h;
        level[h].push_back({i, val});
    }

    for(int i=1;i<=n;i++) sort(level[i].begin(), level[i].end());
    if(level[1].size() != 1){
        cout<<-1;
        return 0;
    }

    for(int h=2;h<=n;h++){
        if(!makeTree(h)){
            cout<<-1;
            return 0;
        }
    }

    int connected = traverse(level[1][0].idx);
    if(connected != n){
        cout<<-1;
        return 0;
    }

    for(int i=1;i<=n;i++){
        cout<<tree[i].first<<' '<<tree[i].second<<'\n';
    }
    return 0;
}