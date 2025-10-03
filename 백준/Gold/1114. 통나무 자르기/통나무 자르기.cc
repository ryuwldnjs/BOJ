#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int L,K,C;
vector<int> a;

//가장긴 통나무가 x이하로 자를떄, 최대C번 베는걸로 해결되는지
bool able(int x){
    int cnt = 0;
    int last = 0;
    for(int i=1;i<K+2;i++){
        if(a[i] - a[i-1] > x) return false; //애초에 못자름

        if(a[i] - last > x){
            cnt++;
            last = a[i-1];
        }
    }
    return cnt <= C;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>L>>K>>C;
    a.resize(K);
    for(int i=0;i<K;i++){
        cin>>a[i];
    }
    a.push_back(0); //시작점
    a.push_back(L); //끝점
    sort(a.begin(), a.end());
    
    int limit = log2(L) + 1;
    int lo=-1, hi=L+1;
    for(int i=0;i<limit;i++){
        int mid = (lo + hi) / 2;
        if(able(mid)) hi = mid;
        else lo = mid+1;
    }
    

    cout<<lo<<' ';


    reverse(a.begin(), a.end());//역순
    int cnt = 0;
    int last = L;
    for(int i=1;i<K+2;i++){
        if(last - a[i] > lo){
            last = a[i-1];
            cnt++;
        }
    }

    //아직 커팅기회가 더 있을때
    if(cnt < C) last = a[K];

    cout<<last;
    return 0;
}