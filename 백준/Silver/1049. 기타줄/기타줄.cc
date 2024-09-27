#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> six_bundle, one;
int n,m;
int main(){
    cin>>n>>m;
    six_bundle.resize(m);
    one.resize(m);
    for(int i=0;i<m;i++){
        cin>>six_bundle[i]>>one[i];
    }
    sort(six_bundle.begin(), six_bundle.end());
    sort(one.begin(), one.end());

    int sixOnly = (n+5)/6 * six_bundle[0]; // 6묶음으로만 사는거
    int mixed = n/6 * six_bundle[0] + (n%6)*one[0]; // 6묶음으로 사고, 남는건 낱개로 구매
    int oneOnly = n * one[0]; // 낱개로만 구매
    

    cout<<min(sixOnly, min(mixed, oneOnly));
    return 0;
}