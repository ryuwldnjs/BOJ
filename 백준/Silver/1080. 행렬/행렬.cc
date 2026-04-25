#include <iostream>
using namespace std;
int n,m, cnt;
int a[55][55],b[55][55];
void changeA(int y, int x){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            a[y+i][x+j] = !a[y+i][x+j];
        }
    }
}
bool isAnswer(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char x; cin>>x;
            a[i][j] = x-'0';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char x; cin>>x;
            b[i][j] = x-'0';
        }
    }

    for(int i=0;i<n-2;i++){
        for(int j=0;j<m-2;j++){
            if(a[i][j] != b[i][j]) {cnt++; changeA(i,j);}
        }
    }

    cout<<(isAnswer() ? cnt : -1);
    return 0;
}