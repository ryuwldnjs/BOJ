
#include <iostream>
#include <vector> //vector<type> Name(length, elements)
#include <algorithm> //heap, set 자료구조랑 sort, merge등 구현
#include <unordered_map> //hashmap 자료구조, O(1)이고 정렬되지 않음
#include <deque> //deque<type>Name(length, elements)

using namespace std;
using ll=long long;
const ll INF = (ll) 1e15;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //code goes here
    ll N, K;
    ll ans=-INF;
    ll minJRev=INF;
    ll minJ=INF;

    cin >> N >> K;
    vector<ll> E(N);
    vector<ll> reverseE(N);
    for (ll i=0;i<N;i++){
        cin >> E[i];
        reverseE[N-1-i]=E[i];
    }
    for (ll i=0;i<N;i++){
        // cout << E[i] << ' ';
    }
    // cout << "\n";
    for (ll i=0;i<N;i++){
        // cout << reverseE[i] << ' ';
    }
    // cout << "\n";
    for (ll i=1;i<N;i++){
        ll j=i-1;

        //SN위치 바꾸는 대신에 배열 뒤집자
        minJRev=min(minJRev, reverseE[j]-K*j);
        minJ=min(minJ, E[j]-K*j);
        ll temp=max(E[i]-K*i-minJ, reverseE[i]-K*i-minJRev);

        ans=max(temp, ans);


    }
    cout << ans;
    return 0;
}