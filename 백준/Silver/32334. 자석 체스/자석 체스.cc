#include <iostream>
using namespace std;
int MIN = 1e9;
int n,d, map[1005][1005], psum[1005][1005];
pair<int,int> ans;
//달라붙는 자석 수
int findStuckCnt(int y, int x){
    int ys = max(y - d, 1);
    int ye = min(y + d, n);
    int xs = max(x - d, 1);
    int xe = min(x + d, n);

    int cnt = psum[ye][xe] - psum[ye][xs-1] - psum[ys-1][xe] + psum[ys-1][xs-1];
    
    return cnt;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
            psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + map[i][j];
            // printf("%d ", psum[i][j]);
        }
        // printf("\n");
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(map[i][j] == 1) continue;
            int tmp = findStuckCnt(i,j);
            if(tmp < MIN){
                MIN = tmp;
                ans = {i,j};
            }
        }
    }

    cout<<ans.first<<' '<<ans.second;
    if(MIN != 0) cout<<'\n'<<MIN;
    return 0;
}