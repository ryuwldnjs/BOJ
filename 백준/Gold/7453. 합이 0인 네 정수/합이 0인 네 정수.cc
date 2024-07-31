#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;
ll  n, answer;
vector<int> a,b,c,d, AB,CD;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    d.resize(n);

    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int sumAB = a[i] + b[j];
            int sumCD = c[i] + d[j];
            AB.push_back(sumAB);
            CD.push_back(sumCD);
        }
    }
    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    for(int i=0;i<AB.size();i++){
        int target = -AB[i];
        ll cnt = upper_bound(CD.begin(), CD.end(), target) - lower_bound(CD.begin(), CD.end(), target);
        answer += cnt;
    }
    cout<<answer;
    return 0;
}