#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int SIZE = 100;
struct Info{
    int val,cnt;

    bool operator<(const Info& other)const{
        if(cnt == other.cnt) return val < other.val;
        return cnt < other.cnt;
    }
};

int r,c,k;
int a[SIZE+5][SIZE+5];

void operate(){
    int sizeR=0, sizeC=0;
    for(int i=0;i<SIZE;i++){
        int lenR = 1;
        int lenC = 1;
        for(int j=0;j<SIZE;j++){
            if(a[i][j]) lenC = j+1;
            if(a[j][i]) lenR = j+1;
        }
        sizeR = max(sizeR, lenR);
        sizeC = max(sizeC, lenC);
    }    

    //R연산
    if(sizeR >= sizeC){
        //i행
        for(int i=0;i<SIZE;i++){
            vector<int> cnt(105);
            vector<Info> line;
            
            for(int j=0;j<SIZE;j++) cnt[a[i][j]]++;
            for(int j=1;j<=100;j++) 
                if(cnt[j] > 0) line.push_back({j, cnt[j]});
            
            sort(line.begin(), line.end());
            for(int j=0;j<line.size();j++){
                a[i][j*2] = line[j].val;
                a[i][j*2+1] = line[j].cnt;
            }
            for(int j=line.size()*2;j<SIZE;j++){
                a[i][j] = 0;
            }
        }


    }
    else{ // C연산
        for(int j=0;j<SIZE;j++){
            vector<int> cnt(105);
            vector<Info> line;
            
            for(int i=0;i<SIZE;i++) cnt[a[i][j]]++;
            for(int i=1;i<=100;i++)
                if(cnt[i] > 0) line.push_back({i, cnt[i]});
        
            sort(line.begin(), line.end());
            for(int i=0;i<line.size();i++){
                a[i*2][j] = line[i].val;
                a[i*2+1][j] = line[i].cnt;
            }
            for(int i=line.size()*2;i<SIZE;i++){
                a[i][j] = 0;
            }
        }
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>r>>c>>k;
    r--; c--;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<=100;i++){
        if(a[r][c] == k){
            cout<<i;
            return 0;
        }
        operate();
    }

    cout<<-1;
    return 0;
}