#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

struct Node{
    Node* mark[26];
    bool flag;

    Node(){
        for(int i=0; i<26; i++) mark[i] = NULL;
        flag = false;
    }

    bool containsKey(char ch){
        return (mark[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node){
        mark[ch-'a'] = node;
    }

    Node* getNext(char ch){
        return mark[ch - 'a'];
    }

    void setEnd(){
        flag = true;   
    }
};

class Trie{
private:
    Node* root;

public: 
    Trie(){
        root = new Node;
    }

    void insert(string word) {
        Node* node = root;

        for(int i=0; i<word.size(); i++){

            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }

            node = node->getNext(word[i]);  
        }

        node->setEnd();  
    }

    bool search(string word){
        Node* node = root;

        for(int i=0; i<word.size(); i++){

            if(!node->containsKey(word[i])) return false;
            
            node = node->getNext(word[i]);
        }

        return node->flag;
    } 

    bool startsWith(string prefix){
        Node* node = root;

        for(int i=0; i<prefix.size(); i++){
            if(!node->containsKey(prefix[i])) return false;
            
            node = node->getNext(prefix[i]);
        }

        return true;
    }

};

void solve() {
    Trie t = Trie();

    t.insert("harsh");
    t.insert("harmonica");
    t.insert("hxxx");

    cout << t.search("xyz") << '\n';
    cout << t.search("harsh") << '\n';
    cout << t.search("har") << '\n';

    cout << "\n\n" ;

    cout << t.startsWith("har") << '\n';
    cout << t.startsWith("hxx") << '\n';
    cout << t.startsWith("h") << '\n';
    cout << t.startsWith("s") << '\n';

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    int _t = 1;
    // cin >> _t;
    while(_t--) {
        solve();
    }

    return 0;
}