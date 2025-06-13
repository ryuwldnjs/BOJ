#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    int d;
    vector<int> algorithm;

    Info() : algorithm(35){}

    bool operator<(const Info&other)const{
        return d < other.d;
    }
};

int getE(vector<int>&psum, int l, int r){
    int all = 0;
    int intersect = 0;
    for(int i=1;i<psum.size();i++){
        if(psum[i]) all++;
        if(psum[i] == r-l+1) intersect++;
    }
    return (all - intersect) * (r - l + 1);
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,k,D;cin>>n>>k>>D;
    vector<Info> students(n);

    for(int i=0;i<n;i++){
        int M,d;cin>>M>>d;
        students[i].d = d;
        for(int j=0;j<M;j++){
            int x;cin>>x;
            students[i].algorithm[x] = 1;
        }
    }

    sort(students.begin(), students.end());
    for(auto s: students){
        // cout<<s.d<<' ';
    }
    vector<int> psum(35);
    for(int i=1;i<=k;i++) psum[i] = students[0].algorithm[i];
    
    int answer = 0;
    int l=0,r=0;
    while(l<=r){
        //효율성계산
        // printf("%d %d : %d\n",l,r,getE(psum, l,r));
        answer = max(answer, getE(psum, l, r));
        
        if(l == r && r < n-1 && students[l].d + D < students[r+1].d){
            for(int i=1;i<=k;i++) psum[i] -= students[l].algorithm[i];
            l++;
            r++;
            for(int i=1;i<=k;i++) psum[i] += students[r].algorithm[i];
        }
        else if(r >= n-1 || students[l].d + D < students[r+1].d){
            for(int i=1;i<=k;i++) psum[i] -= students[l].algorithm[i];
            l++;
        }
        else {
            r++;
            for(int i=1;i<=k;i++) psum[i] += students[r].algorithm[i];
        }
    }
    
    cout<<answer;
    return 0;
}