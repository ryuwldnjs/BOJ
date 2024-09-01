#include <iostream>
#include <vector>
using namespace std;
struct Info{
    int x, y, ver;
    int p; //사진찍음
};

vector<int> parent(3000+5, -1), answer;
vector<Info> friends; //0번은 푸앙이 자리
Info puang;

int n,k,t;

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
bool ableToConnect(Info a, Info b){
    double dist2 = (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
    int ver_diff = abs(a.ver - b.ver);
    if(dist2 <= k*k && ver_diff <= t) return true; //간선 연결 가능
    return false;
}

int main(){
    cin>>n>>k>>t;
    int X,Y,Ver; cin>>X>>Y>>Ver;
    puang.x = X;
    puang.y = Y;
    puang.ver = Ver;
    friends.push_back(puang); //푸앙이도 넣어줘야 같은 컴포넌트인지 체크가능. 푸앙이가 0번

    for(int i=1;i<=n;i++){
        int a,b,c,d; cin>>a>>b>>c>>d;
        Info tmp = {a,b,c,d};
        friends.push_back(tmp);

        for(int j=0;j<friends.size()-1; j++){ // size최소1 보장
            if(ableToConnect(friends[j], friends[i])){
                merge(i, j);
            }   
        }
    }

    for(int i=1;i<friends.size(); i++){
        if(find(i) == find(0) && friends[i].p == 1){ // 푸앙이랑 같은 컴포넌트중에서 사진있는놈들
            answer.push_back(i);
        }
    }
    if(answer.empty()) cout<<0;
    else{
        for(auto x : answer){
            cout<<x<<' ';
        }
    }
    return 0;
}