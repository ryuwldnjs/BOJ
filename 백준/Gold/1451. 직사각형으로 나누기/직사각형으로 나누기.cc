#include <iostream>
#include <algorithm>
using namespace std;
using ll=long long;
ll n,m;
ll psum[55][55];
ll total=0, MAX = -1;
ll cal_psum(ll yl, ll xl, ll yr ,ll xr){
    return psum[yr][xr] - psum[yr][xl-1] - psum[yl-1][xr] + psum[yl-1][xl-1];
}


int main(){
    
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char x; cin>>x;
            ll num = x - '0';
            psum[i][j] = psum[i][j-1] + psum[i-1][j] - psum[i-1][j-1] + num;
            total += num;
        }
    }

    // ||| 모양
    for(int i=1;i<=m;i++){
        for(int j=i+1;j<=m;j++){
            ll first = cal_psum(1,1, n,i);
            ll second = cal_psum(1,i+1, n,j);
            ll third = (ll) total - first - second;
            // int product = first * second * third;
            MAX = max(MAX, first * second * third);
        }
    }

/*
햄버거 모양
*/
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ll first = cal_psum(1,1, i,m);
            ll second = cal_psum(i+1,1, j,m);
            ll third = (ll) total - first - second;
            // int product = first * second * third;
            MAX = max(MAX, first * second * third);
        }
    }

/*
ㅏ : 작은애들2개 오른쪽
*/
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ll first = cal_psum(1, j, i, m);
            ll second = cal_psum(i+1, j, n, m);
            ll third = (ll) total - first - second;
            MAX = max(MAX, first * second * third);
        }
    }

/*
ㅓ : 작은애들2개는 왼쪽
*/
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ll first = cal_psum(1, 1, i, j);
            ll second = cal_psum(i+1, 1, n, j);
            ll third = (ll) total - first - second;
            MAX = max(MAX, first * second * third);
        }
    }


/*
ㅜ : 작은애들2개 아랫쪽
*/
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ll first = cal_psum(i, 1, n, j);
            ll second = cal_psum(i, j+1, n, m);
            ll third = (ll) total - first - second;
            MAX = max(MAX, first * second * third);
        }
    }

/*
ㅗ : 작은애들2개는 왼쪽
*/
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ll first = cal_psum(1, 1, i, j);
            ll second = cal_psum(1, j+1, i, m);
            ll third = (ll) total - first - second;
            MAX = max(MAX, first * second * third);
        }
    }
    cout<<MAX;

    return 0;
}