#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;
struct Point{
    ll x,y;
    int idx;
    bool operator<(const Point& other)const{
        if(x == other.x) return y < other.y;
        return x < other.x;
    }
};

int n;
vector<Point> p, answer;

int ccw(Point a, Point b, Point c){
    ll val = (a.x*b.y + b.x*c.y + c.x*a.y) - (a.y*b.x + b.y*c.x + c.y*a.x);
    if(val > 0) return 1;
    if(val == 0) return 0;
    if(val < 0) return -1;
}

//윗껍질만 구현
//나머지 부분은 x축 정렬해서 넣기
void convex_hull(){
    sort(p.begin(), p.end());
    stack<Point> s;
    s.push(p[0]); s.push(p[1]);

    for(int i=2;i<p.size();i++){
        while(s.size() >= 2){
            Point b = s.top(); s.pop();
            Point a = s.top();

            if(ccw(a, b, p[i]) <= 0){
                s.push(b);
                break;
            }
        }
        s.push(p[i]);
    }
    //윗껍질을 오른쪽에서 왼쪽으로 역순으로 넣기
    while(!s.empty()){
        answer.push_back(s.top());
        s.pop();
    }
    //윗껍질부분은 제외시킨뒤, 정렬된 순서대로 넣기
    set<Point> exclude(answer.begin(), answer.end());
    for(int i=0;i<p.size();i++){
        if(exclude.count(p[i]) > 0) continue;
        answer.push_back(p[i]);
    }
}
void solve(){
    cin>>n;
    p = vector<Point>();
    answer = vector<Point>();
    for(int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        p.push_back({x,y, i});
    }
    convex_hull();

    for(int i=0;i<answer.size();i++){
        cout<<answer[i].idx<<' ';
    }
    cout<<'\n';
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}