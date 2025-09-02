#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

vector<int> all, colors[200000+5];
vector<int> all_prefix, colors_prefix[200000+5];
int c[200000+5], s[200000+5];

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;

    for(int i=0;i<n;i++){
        cin>>c[i]>>s[i];
        all.push_back(s[i]);
        colors[c[i]].push_back(s[i]);
    }

    sort(all.begin(), all.end());
    all_prefix.resize(all.size());
    for(int i=0;i<n;i++){
        all_prefix[i] = all[i];
        if(i>0) all_prefix[i] += all_prefix[i-1];
    }

    for(int i=0;i<=n;i++){
        sort(colors[i].begin(), colors[i].end());
        colors_prefix[i].resize(colors[i].size());
        for(int j=0;j<colors[i].size();j++){
            colors_prefix[i][j] = colors[i][j];
            if(j>0) colors_prefix[i][j] += colors_prefix[i][j-1];
        }
    }



    for(int i=0;i<n;i++){
        vector<int> &color = colors[c[i]];
        vector<int> &color_prefix = colors_prefix[c[i]];
        int size = s[i];

        int idx_all = lower_bound(all.begin(), all.end(), size) - all.begin() - 1;
        int idx_color = lower_bound(color.begin(), color.end(), size) - color.begin() - 1;
        int ret = 0;
        if(idx_all >= 0) ret += all_prefix[idx_all];
        if(idx_color >= 0) ret -= color_prefix[idx_color];
        cout<<ret<<'\n';
    }
    return 0;
}