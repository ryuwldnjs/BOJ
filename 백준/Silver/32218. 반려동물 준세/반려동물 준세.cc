#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> map(10000);

bool isZero(vector<int>& arr){
    for(auto x : arr){
        if(x != 0) return false;
    }
    return true;
}
void makeArray(vector<int>& A, vector<int>& B){
    B.resize(n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(A[i] < A[j]) B[i]++;
        }
    }
}

int main(){
    cin>>n;
    map[0].resize(n);
    for(int i=0;i<n;i++) cin>>map[0][i];
    for(int i=0;;i++){
        if(isZero(map[i])) {
            cout<<i+1;
            return 0;
        }
        makeArray(map[i], map[i+1]);
    }
    return 0;
}