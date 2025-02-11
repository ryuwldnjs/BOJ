#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
class Node{
public:
    unordered_map<char, Node*> children;
    bool isEndOfWord = false;
};

class Trie{
public:
    Node* root;
    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;
        for(char ch: word){
            if(node->children.count(ch) == 0)
                node->children[ch] = new Node();
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }
    bool isExisted(string word){
        Node* node = root;
        for(char ch: word){
            if(node->children.count(ch) == 0) return false;
            node = node->children[ch];
        }
        return node->isEndOfWord;
    }
    bool search(string word){
        Node *node = root;
        for(char ch: word){
            if(node->children.count(ch) == 0) return true;
            node = node->children[ch];
            if(node->isEndOfWord) return false;
        }
        return false;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        Trie trie;
        bool isAnswer = true;
        int n; cin>>n;
        for(int i=0;i<n;i++){
            string num; cin>>num;
            isAnswer &= trie.search(num);
            trie.insert(num);
        }
        cout<<(isAnswer ? "YES" : "NO")<<'\n';
    }
    return 0;
}