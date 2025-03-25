#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;
struct Info{
    int a,b,c;
    bool operator<(const Info& other)const{
        return b < other.b;
    }
};
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,c,m; cin>>n>>c>>m;
    vector<int> load(n+1);
    vector<Info> arr;
    for(int i=0;i<m;i++){
        int a,b,c; cin>>a>>b>>c;
        arr.push_back({a,b,c});
    }
    sort(arr.begin(), arr.end());
    int answer = 0;
    //끝나는점이 가장 빠른 택배부터
    for(int i=0;i<m;i++){
        int s = arr[i].a;
        int e = arr[i].b;
        int cnt = arr[i].c;

        int MIN = c; //가장 대역폭이 작은 순간의 값
        for(int j=e-1;j>=s;j--){
            MIN = min(MIN, c - load[j]);
            MIN = max(MIN,0);
        }
        MIN = min(MIN, cnt);
        //i번 택배를 시작점부터 가능한 최대로 적재하고, 기록
        for(int j=s;j<e;j++){
            load[j] += MIN;
        }
        
        answer += MIN;
    }
    cout<<answer;
    return 0;
}