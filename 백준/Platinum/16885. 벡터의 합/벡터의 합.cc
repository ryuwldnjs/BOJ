#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#define INF (int)1e9
using namespace std;
struct Point{
    int x,y, idx;
    bool operator<(const Point &other)const{
        return y < other.y;
    }
};
bool cmp(Point a, Point b){
    return a.x < b.x;
}
int dist(Point a, Point b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
vector<Point> original, p;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        original.push_back({a,b,i});
        p.push_back({abs(a),abs(b), i});
    }
    
    sort(p.begin(), p.end(), cmp);
    set<Point> s;
    s.insert(p[0]); s.insert(p[1]);
    int MIN = dist(p[0], p[1]);
    pair<int,int> answer={p[0].idx, p[1].idx};
    int start = 0;

    for(int i=2;i<n;i++){
        Point now = p[i];
        while(start<i && (now.x - p[start].x)*(now.x - p[start].x) > MIN){
            s.erase(p[start++]);
        }

        int dy = sqrt(MIN)+2;
        auto lo = s.lower_bound({-INF, now.y - dy});
        auto hi = s.lower_bound({+INF, now.y + dy});

        for(auto it=lo; it!=hi; it++){
            // MIN = min(MIN, dist(now, *it));
            if(MIN > dist(now, *it)){
                MIN = dist(now, *it);
                answer = {now.idx, it->idx};
            }
        }
        s.insert(now);
    }
    // cout<<MIN<<'\n';
    // cout<<answer.first<<' '<<answer.second;
    int a = answer.first; int b = answer.second;
    int k1=1,k2=4;
    if(original[a].x < 0) k1++;
    if(original[a].y < 0) k1+=2;
    if(original[b].x < 0) k2--;
    if(original[b].y < 0) k2-=2;
    
    cout<<a+1<<' '<<k1<<' '<<b+1<<' '<<k2;
    return 0;
}