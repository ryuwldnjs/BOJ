#include <iostream>
#include <vector>
using namespace std;
vector<int> money;
int n,m;
bool able(int x){
    int balance = 0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(x < money[i]) return false;

        if(balance < money[i]){
            balance = x;
            cnt++;
        }
        balance -= money[i];
    }
    return cnt <= m;
}
int main(){
    cin>>n>>m;
    money.resize(n);
    for(int i=0;i<n;i++){
        cin>>money[i];
    }

    int l=0, r=1e9;
    for(int i=0;i<100;i++){
        int mid = (l+r) / 2;
        if(able(mid)) r = mid;
        else l=mid+1;
        // printf("%d ", l);
    }
    cout<<l;
    return 0;
}