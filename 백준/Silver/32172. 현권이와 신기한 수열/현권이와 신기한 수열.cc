#include <iostream>
using namespace std;
int n, before;
bool isExist[100000*10] = {true,};
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int now = before - i;
        // printf("%d %d\n", i, now);
        if(now<0 || isExist[now]){
            now = before + i;
        }

        isExist[now] = true;
        before = now;
    }
    cout<<before;
    return 0;
}