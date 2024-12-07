#include <iostream>
using namespace std;
int f[10], f_inverse[10];

int main(){
    for(int i=0;i<10;i++){
        cin>>f[i];
        f_inverse[f[i]] = i;
    }
    string f_a,f_b;
    string a,b;
    cin>>f_a>>f_b;

    for(char x: f_a){
        a += to_string(f_inverse[x - '0']);
    }
    for(char x: f_b){
        b += to_string(f_inverse[x - '0']);
    }
    string ab = to_string(stoi(a) + stoi(b));
    string f_ab;
    for(char x: ab){
        f_ab += to_string(f[x - '0']);
    }
    cout<<f_ab;
    return 0;
}