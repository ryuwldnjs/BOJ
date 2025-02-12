#include <iostream>
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
        root = new Node();
    }
    ~Trie(){
        deleteTrie(root);
    }
    void deleteTrie(Node *node){
        for(auto child: node->children){
            deleteTrie(child.second);
        }
        delete node;
    }
    void insert(string& word){
        Node* node = root;
        for(char ch: word){
            if(node->children.count(ch) == 0){
                node->children[ch] = new Node();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    int getTrialCount(string& word){
        Node* node = root;
        int cnt = 0;
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            if(i==0 || node->children.size() > 1 || node->isEndOfWord == true){ // 자식이 하나뿐일때
                cnt++;            
            }
            node = node->children[ch];
        }
        return cnt;
    }
};

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cout<<fixed; cout.precision(2);
    while(cin>>n){
        Trie trie;
        vector<string> words;
        double answer = 0;
        for(int i=0;i<n;i++){
            string word; cin>>word;
            trie.insert(word);
            words.push_back(word);
        }
        for(string word: words){
            answer += trie.getTrialCount(word);
        }
        answer /= n;
        cout<<answer<<'\n';

    }
    return 0;
}