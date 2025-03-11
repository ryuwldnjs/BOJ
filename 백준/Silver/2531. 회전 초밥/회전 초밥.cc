#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(0) ->sync_with_stdio(0);
    int n,d,k,c; cin>>n>>d>>k>>c;
    vector<int> arr(n);
    vector<int> sushi(d+1);
    //sushi[i]: i초밥이 등장한 수
   
    int cnt=0, answer=0;
    for(auto &i: arr) cin>>i;

    for(int i=0;i<k;i++){
        // sushi[arr[i]]++;
        if(++sushi[arr[i]] == 1) cnt++;
        answer = cnt;
        if(sushi[c]==0) answer++;
    }

    for(int i=0;i<n;i++){
        int l = i;//사라질 왼쪽
        int r = (i+k) % n;//새로 들어올 오른쪽

        
        if(--sushi[arr[l]]==0) cnt--;
        if(++sushi[arr[r]]==1) cnt++;
        
        if(sushi[c]==0) answer = max(answer, cnt + 1);
        else answer = max(answer, cnt);
    }

    cout<<answer;
    return 0;
}