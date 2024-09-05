#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
bool cmp1(pii a, pii b){
    return a.first > b.first;
}
bool cmp2(pii a, pii b){
    return a.second > b.second;
}
ll n,m,k;
vector<pii> students;
ll answer;
int main(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        ll a,b; cin>>a>>b;
        students.push_back({a,b});
    }
    sort(students.begin(), students.end(), cmp2);
    for(int i=0;i<k;i++){
        answer += students[i].first;
    }
    
    sort(students.begin()+k, students.end(), cmp1);
    for(int i=k;i<m+k;i++){
        answer += students[i].first;
    }
    
    cout<<answer;
    return 0;
}