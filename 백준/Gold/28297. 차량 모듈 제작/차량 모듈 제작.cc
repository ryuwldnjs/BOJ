#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const double PI = acos(0.0) * 2;

struct Info{
    double x,y;
    double r;
};
struct Edge{
    int a,b;
    double cost;

    bool operator<(const Edge& other)const{
        return cost < other.cost;
    }
};

bool isIntersect(Info&a, Info&b){
    double dist2 = (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
    if(dist2 <= (a.r + b.r)*(a.r + b.r)) return true;
    return false;
}

double getLength(Info a, Info b){
    if(a.r < b.r) swap(a,b);
    double dist = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
    double theta = acos((b.r - a.r) / dist);

    double length = a.r * theta + b.r * (PI - theta) + sqrt(dist*dist - (a.r-b.r)*(a.r-b.r));
    return length * 2;
}


vector<int> parent;
int find(int x){
    if(parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}
int merge(int a, int b){
    a = find(a);
    b = find(b);
    
    if(a == b) return 0;
    parent[a] += parent[b];
    parent[b] = a;
    return 1;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    vector<Info> arr(n);
    parent.resize(n, -1);
    for(int i=0;i<n;i++){
        double a,b,c;cin>>a>>b>>c;
        arr[i] = {a,b,c};
    }

    vector<Edge> edges;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(isIntersect(arr[i], arr[j])) edges.push_back({i, j, 0});
            else edges.push_back({i,j, getLength(arr[i], arr[j])});
        }
    }


    sort(edges.begin(), edges.end());

    double answer = 0;
    for(Edge e: edges){
        // printf("%d %d %lf\n",e.a, e.b, e.cost);
        if(merge(e.a, e.b)) answer += e.cost;
    }

    cout.precision(13);
    cout<<answer;
    return 0;
}