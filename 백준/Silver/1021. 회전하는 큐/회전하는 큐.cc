#include <iostream>
#include <deque>
using namespace std;
deque<int> dq;
int n,m, ans;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) dq.push_back(i);

    for(int i=0;i<m;i++){
        int target; cin>>target;

        deque<int> a(dq),b(dq);
        int cnt_a=0, cnt_b=0;
        while(a.front() != target){
            a.push_back(a.front());
            a.pop_front();
            cnt_a++;
        }
        a.pop_front();
        while(b.front() != target){
            b.push_front(b.back());
            b.pop_back();
            cnt_b++;
        }
        b.pop_front();

        if(cnt_a < cnt_b){
            dq = a;
            ans += cnt_a;
        }
        else{
            dq = b;
            ans += cnt_b;
        }
    }
    cout<<ans;
    return 0;
}