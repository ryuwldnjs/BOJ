#include <bits/stdc++.h>
using namespace std;
using ll=long long;

unordered_map<ll, ll> parent;
ll find(ll x){
    if(parent[x] == 0) return x;
    return parent[x] = find(parent[x]);
}
int merge(ll a, ll b){
    a = find(a);
    b = find(b);
    if(a == b) return 0;
    parent[a] = b; // a의 부모를 b로 설정
    return 1;
}
vector<ll> solution(ll k, vector<ll> room_number) {
    vector<ll> answer;
    for(ll num : room_number){
        ll target = find(num);
        answer.push_back(target);
        merge(target, target+1);
    }
    return answer;
}