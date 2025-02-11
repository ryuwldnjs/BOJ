#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
class Node{
public:
    map<string, Node*> children;
};
class Trie{
public:
    Node* root;
    Trie(){
        root = new Node();
    }
    
    void insert(vector<string>& words){
        Node* node = root;
        for(string word: words){
            if(node->children.count(word) == 0){
                node->children[word] = new Node();
            }
            node = node->children[word];
        }
    }
    void print(){
        print(root, 0);
    }
    void print(Node* node, int level){
        for(auto it=node->children.begin(); it!= node->children.end(); it++){
            for(int i=0;i<level;i++) cout<<"--";
            cout<<it->first<<'\n';
            print(it->second, level+1);
        }
    }
};
int main(){
    Trie trie;
    int n; cin>>n;
    while(n--){
        int k; cin>>k;
        vector<string> words;
        for(int i=0;i<k;i++){
            string word; cin>>word;
            words.push_back(word);
        }
        trie.insert(words);
    }
    trie.print();
    return 0;
}