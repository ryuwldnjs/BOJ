#include <iostream>
#include <vector>
using namespace std;

int n, MAX;
vector<int> arr;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        char c; cin>>c;
        if(c == 'S') arr.push_back(0);
        else if(c == 'P') arr.push_back(1);
        else if(c == 'R') arr.push_back(2);
    }

    for(int i=0;i<3;i++){
        int required = i;
        vector<int> answer;
        for(int j=0;j<arr.size();j++){
            if(arr[j] != required) continue;
            answer.push_back(required);
            required = (required + 1) % 3;
        }
        if(answer.size() % 3 == 0) MAX = max(MAX, n - (int)answer.size());
    }
    cout<<MAX;
    return 0;
}