#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;
struct Point{
    ll x,y;
    bool operator<(const Point& other)const{
        if(x == other.x) return y < other.y;
        return x < other.x;
    }
};

int n;
vector<Point> p, hull;
double dist(Point a, Point b, Point target){
    //직선AB와 점p의 거리
    double A = b.y - a.y;
    double B = a.x - b.x;
    double C = b.x*a.y - a.x*b.y;
    return (double) abs(A*target.x + B*target.y + C) / sqrt(A*A + B*B);
}
int ccw(Point a, Point b, Point c){
    ll val = (a.x*b.y + b.x*c.y + c.x*a.y) - (a.y*b.x + b.y*c.x + c.y*a.x);
    if(val > 0) return 1;
    if(val == 0) return 0;
    if(val < 0) return -1;
}

double convex_hull(){
    stack<Point> s1, s2;
    sort(p.begin(), p.end());
    
    s1.push(p[0]); s1.push(p[1]);
    for(int i=2;i<n;i++){
        while(s1.size() >= 2){
            Point b = s1.top(); s1.pop();
            Point a = s1.top();

            if(ccw(a, b, p[i]) < 0){
                s1.push(b);
                break;
            }
        }
        s1.push(p[i]);
    }

    //아랫껍질
    s2.push(p[0]); s2.push(p[1]);
    for(int i=2;i<n;i++){
        while(s2.size() >= 2){
            Point b = s2.top(); s2.pop();
            Point a = s2.top();

            if(ccw(a, b, p[i]) > 0){ // 시계반대
                s2.push(b);
                break;
            }
        }
        s2.push(p[i]);
    }
    //시계 순서대로 정렬
    while(!s1.empty()){
        hull.push_back(s1.top());
        s1.pop();
    }
    reverse(hull.begin(), hull.end()); // 시계방향으로 정리

    s2.pop();//양끝 겹치는 두점은 제외
    while(s2.size() > 1){
        hull.push_back(s2.top());
        s2.pop();
    }

    double answer = 1e9;
    for(int i=0;i<hull.size();i++){
        Point a = hull[i];
        Point b = hull[(i+1)%hull.size()];
        //직선AB

        //각 직선에서 가장 거리가 먼 꼭지점의 거리를 체크
        double MAX = 0;
        for(int j=0; j<hull.size(); j++){
            MAX = max(MAX, dist(a, b, hull[j]));
        }
        // 각 직선별로 구한 거리들중 최솟값
        // min(max()) 구조
        answer = min(answer, MAX);
    }
    return answer;
}

void solve(int tc){
    p = hull = vector<Point>();
    for(int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        p.push_back({x,y});
    }

    double answer = convex_hull();

    // answer = ceil(answer * 100.0) / 100.0;
    answer += 0.005;
    cout.precision(2);
    cout<< fixed << "Case "<<tc<<": "<<answer<<'\n';
}   

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    for(int tc=1; ; tc++){
        cin>>n;
        if(n==0) break;
        solve(tc);
    }
    return 0;
}