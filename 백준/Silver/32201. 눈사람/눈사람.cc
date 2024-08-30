#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, int> before;
int n, MAX;
vector<int> answer;
int main(){
    cin>>n;
    // before.resize(n);
    for(int i=0;i<n;i++){
        int x; cin>>x;
        before[x] = i;
    }
    for(int i=0;i<n;i++){
        int x; cin>>x;
        int diff = before[x] - i;
        if(diff > MAX){
            answer = vector<int>();
            MAX = diff;
        }
        if(diff == MAX){
            answer.push_back(x);
        }
    }

    for(auto x:  answer){
        cout<<x<<' ';
    }
    return 0;
}