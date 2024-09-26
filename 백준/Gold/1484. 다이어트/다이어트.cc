#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 기존 : x
 * 이후 : x + dx
 * G = (x+dx)^2 - x^2 = 2xdx + dx^2 = dx(2x + dx)
 * dx=[0,...sqrt(G)] 순차 대입 
 * 2x + dx = G / dx
 * x = (G - dx^2) / 2dx
 */
int G;
vector<int> answer;
int main(){
    cin>>G;
    for(int dx=1;dx*dx<=G;dx++){
        if((G - dx*dx) % (2*dx) == 0 && (G - dx*dx) / (2*dx) != 0)
            answer.push_back((G - dx*dx) / (2*dx) + dx);
            // printf("%d %d\n", (G - dx*dx) / (2*dx), (G - dx*dx) / (2*dx) + dx);
    }
    sort(answer.begin(), answer.end());
    if(answer.empty()) cout<<-1;
    for(auto x : answer) cout<<x<<'\n';
    return 0;
}