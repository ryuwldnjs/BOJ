#include <iostream>
#include <string>
#include <map>
using namespace std;
struct Node{
    map<char, Node*> children;
    bool isEndOfWord;
    bool isBanned;
    int cntOfWord;
};
struct Trie{
    Node* root;
    Trie(){
        root = new Node();
    }
    ~Trie(){
        deleteNode(root);
    }
    void deleteNode(Node* node){
        for(auto it=node->children.begin(); it!=node->children.end();it++){
            deleteNode(it->second);
        }
        delete node;
    }
    void insert(string word){
        Node* node = root;
        for(char ch: word){
            if(node->children.count(ch) == 0) node->children[ch] = new Node();
            node->cntOfWord++;
            node = node->children[ch];
        }
        node->cntOfWord++;
        node->isEndOfWord = true;
    }
    void insert(string word, bool __){//지우면 안되는 단어 삽입
        Node* node = root;
        for(char ch: word){
            if(node->children.count(ch) == 0) node->children[ch] = new Node();
            node->isBanned = true;
            node = node->children[ch];
        }
        node->isBanned = true;
        node->isEndOfWord = true;
    }

    int calculate(int remain){
        Node* node = root;
        return traverse(node, remain) + remain;
    }

    int traverse(Node* node, int& remain){
        int cnt = 0;
        if(node->isBanned == false){
            remain -= node->cntOfWord;
            return 1;
        }

        for(auto it=node->children.begin(); it!=node->children.end();it++){
            cnt += traverse(it->second, remain);
        }
        return cnt;
    }
};

void solve(){
    Trie trie;
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++){
        string str; cin>>str;
        trie.insert(str);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        string str; cin>>str;
        trie.insert(str, true);
    }
    cout<<trie.calculate(n)<<'\n';
}

int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}