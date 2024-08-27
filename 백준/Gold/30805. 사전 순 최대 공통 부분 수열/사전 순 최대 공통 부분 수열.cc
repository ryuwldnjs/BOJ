#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
vector<vector<int> > a(101),b(101); // a[i] : 원소i의 위치가 저장됨
vector<int> answer;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a[x].push_back(i);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int x;cin>>x;
        b[x].push_back(i);
    }

    int a_idx = -1, b_idx = -1;
    for(int i=100;i>=1;){ // 최적의 답은 가장 큰 수부터 앞에서부터 넣는것임. [9 9 9]이 나올수도 있으므로, 항상 i--를 하면 안됨.
        int a_target = upper_bound(a[i].begin(), a[i].end(), a_idx) - a[i].begin();
        int b_target = upper_bound(b[i].begin(), b[i].end(), b_idx) - b[i].begin();
        if(a_target == a[i].size() || b_target == b[i].size()){ // 100..99..98..97이 어느한곳이라도 없으면 건너뜀
            i--;
            continue;
        }
        answer.push_back(i);
        a_idx = a[i][a_target];
        b_idx = b[i][b_target];
        // i++;
    }
    cout<<answer.size()<<'\n';
    for(int i : answer){
        cout<<i<<' ';
    }
    return 0;
}