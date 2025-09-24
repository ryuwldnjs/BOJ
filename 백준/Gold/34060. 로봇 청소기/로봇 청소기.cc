#include <bits/stdc++.h>
using namespace std;
struct Info{
    int y;
    int idx;

    bool operator<(const Info &other)const{
        return y < other.y;
    }
    bool operator<(const int other)const{
        return y < other;
    }
    
};


vector<int> parent, y;
int find(int x){
    if(parent[x] < 0) return x;

    return parent[x] = find(parent[x]);
}

int merge(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return false;
    parent[a] += parent[b];
    parent[b] = a;
    return 1;
}




int main(){
    int n;cin>>n;
    parent.resize(n, -1);
    y.resize(n);
    for(int i=0;i<n;i++){
        cin>>y[i];
    }

    //직전 줄, 지금 줄
    vector<Info> pre, now;
    now.push_back({y[0], 0});
    for(int i=1;i<n;i++){
        //다음 열로 넘겨야함
        if(y[i-1] >= y[i]){
            swap(pre, now);
            now.clear();
            now.push_back({y[i], i});
            int idx = lower_bound(pre.begin(), pre.end(), y[i]) - pre.begin();
            if(idx < pre.size() && pre[idx].y == y[i]) merge(pre[idx].idx, i);
        
            continue;
        }
        int idx = lower_bound(pre.begin(), pre.end(), y[i]) - pre.begin();
        if(idx < pre.size() && pre[idx].y == y[i]) merge(pre[idx].idx, i);
        
        if(now.size() && now.back().y + 1 == y[i]) merge(i-1, i);
        now.push_back({y[i], i});
    }

    int answer = 0;
    for(int i=0;i<n;i++){
        if(parent[i] < 0) answer++;
    }
    cout<<answer<<'\n'<<n;
    return 0;
}