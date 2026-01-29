#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int s,n,k;
int r1,r2,c1,c2;
//정답 행렬 구역의 바깥인지
bool isOutter(int y1, int x1, int y2, int x2){
    return r2<y1 || r1>y2 || c2<x1 || c1>x2;
}

int answer[55][55];
// 닫힌계
void solve(int y1, int x1, int y2, int x2, bool isCenter){
    //기저
    if(isCenter){
        for(int i=r1;i<=r2;i++){
            for(int j=c1;j<=c2;j++){
                if(y1<=i&&i<=y2 && x1<=j&&j<=x2) answer[i - r1][j - c1] = 1;
            }
        }
        return;
    }
    if(y1==y2) return; //검정 영역은 아니지만, 사이즈=1칸 영역

    //분할
    int blockSize = (y2 - y1 + 1) / n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int yy1 = y1 + blockSize * i;
            int xx1 = x1 + blockSize * j;

            int yy2 = yy1 + blockSize - 1;
            int xx2 = xx1 + blockSize - 1;

            if(isOutter(yy1, xx1, yy2, xx2)) continue; //무시

            //재귀분할 영역
            if(i<(n-k)/2 || j<(n-k)/2 || i>=(n+k)/2 || j>=(n+k)/2) solve(yy1, xx1, yy2, xx2, false);
            //정복 영역
            else solve(yy1, xx1, yy2, xx2, true);
        }
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>s>>n>>k>>r1>>r2>>c1>>c2;
    
    ll SIZE = 1;
    for(int i=0;i<s;i++) SIZE *= n;

    solve(0, 0, SIZE-1, SIZE-1, false);

    for(int i=0;i<=r2-r1;i++){
        for(int j=0;j<=c2-c1;j++){
            cout<<answer[i][j];
        }
        cout<<'\n';
    }
    return 0;
}