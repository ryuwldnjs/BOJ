#include <iostream>
#include <string>
using namespace std;
int a,b,c;
int main(){
    cin>>a>>b>>c;
    cout<<a+b-c << '\n' << stoi(to_string(a) + to_string(b)) - c;
    return 0;
}