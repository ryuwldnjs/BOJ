#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    ll a,b,c;
    //개수, 유통기한, 만족도

    //만족도 높은거 우선
    bool operator<(const Info& other)const{
        return c < other.c;
    }
};

void solve(){
    ll n,k;cin>>n>>k;
    vector<Info> coffee(n);
    for(int i=0;i<n;i++){
        ll a,b,c;cin>>a>>b>>c;
        coffee[i] = {a,b,c};
    }
    sort(coffee.begin(), coffee.end(), [](Info x, Info y){
        return x.b > y.b;
    });
    coffee.push_back({0,0,0}); //경계
    // for(int i=0;i<coffee.size();i++){
    //     printf("%d %d %d\n", coffee[i].a,coffee[i].b,coffee[i].c);
    // }


    priority_queue<Info> pq;

    ll day = coffee[0].b;
    ll answer = 0;
    for(int i=0;i<n;i++){
        if(coffee[i].b == coffee[i+1].b){//유통기한 같은것들은 다같이 넣고 판단
            pq.push(coffee[i]);
            continue;
        }
        pq.push(coffee[i]);
        ll nextday = coffee[i+1].b;
        //nextday전까지 먹을 커피 선택
        while(!pq.empty() && day > nextday){
            Info target = pq.top();
            // printf("%d, %d\n", day, target.b);
            pq.pop();
            if(day - target.a >= nextday){ 
                answer += target.a * target.c;
                day -= target.a;
            }
            else{ //커피 다 쓰면 안됨
                target.a -= day - nextday;
                answer += (day - nextday) * target.c;
                day = nextday;
                pq.push(target);
            }
        }
        day = nextday; 
        //커피를 다 먹어도 nextday가 안될수도 있음
        //커피 없는 나날들을 보내야함

    }
    cout<<answer<<'\n';

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; for(int tc=1;tc<=t;tc++) {cout<<"Case #"<<tc<<": "; solve();}
    return 0;
}