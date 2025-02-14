#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
struct Node{
    map<char, Node*> children;
    bool isEndOfWord;
};
struct Trie{
    Node* root;
    Trie(){
        root =  new Node();
    }

    void insert(string& word){
        Node* node = root;
        for(char ch: word){
            if(node->children.count(ch) == 0) node->children[ch] = new Node();
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }
    void search(string& word, vector<bool>& isEnd, bool isReversed){
        Node* node = root;
        if(isReversed){
            for(int i=word.size()-1;i>=0;i--){
                char ch = word[i];
                if(node->children.count(ch) == 0) return;
                node = node->children[ch];
                if(node->isEndOfWord) isEnd[i] = true;
            }
        }
        else{
            for(int i=0;i<word.size();i++){
                char ch = word[i];
                if(node->children.count(ch) == 0) return;
                node = node->children[ch];
                if(node->isEndOfWord) isEnd[i] = true;
            }
        }
        
    }
};
Trie trie_color, trie_name;
int c,n,q;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>c>>n;
    for(int i=0;i<c;i++){
        string color; cin>>color;
        trie_color.insert(color);
    }
    for(int i=0;i<n;i++){
        string name; cin>>name;
        reverse(name.begin(), name.end());
        trie_name.insert(name);
    }

    cin>>q;
    while(q--){
        bool isAnswer = false;
        string name; cin>>name;
        vector<bool> left(name.size()), right(name.size());
        trie_color.search(name, left, false);
        trie_name.search(name, right, true);

        for(int i=0;i<left.size()-1;i++){
            if(left[i]==true && right[i+1]==true){
                isAnswer = true;
                break;
            }
        }
        cout<<(isAnswer ? "Yes\n" : "No\n");
    }
    return 0;
}