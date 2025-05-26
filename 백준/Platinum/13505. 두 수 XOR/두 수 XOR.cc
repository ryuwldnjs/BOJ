#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Node{
    Node* child[2];
    bool endOfWord;
};
struct Trie{
    Node* root;
    Trie(){
        root = new Node();
    }

    void insert(int x){
        Node* now = root;
        for(int i=31;i>=0;i--){
            bool target = x & (1<<i);
            if(!now->child[target]) now->child[target] = new Node();
            now = now->child[target];
        }
        now->endOfWord = true;
    }

    int search(int x){
        Node* now = root;
        int ret = 0;
        for(int i=31; i>=0; i--){
            bool target = x & (1<<i);
            // int target = !!(x & (1<<i));
            bool opposite = !target;

            if(now->child[opposite]){
                ret += (1<<i);
                now = now->child[opposite];
            }else{
                now = now->child[target];
            }

        }
        return ret;
    }
};
void solve(){

}
Trie trie;
vector<int> arr;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        trie.insert(arr[i]);
    }
    int answer = 0;
    for(int i=0;i<n;i++){
        answer = max(answer, trie.search(arr[i]));
    }
    cout<<answer;
    return 0;
}