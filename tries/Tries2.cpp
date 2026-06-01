#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

struct Node {
    Node* mark[26];
    int ew;
    int cp;
    bool flag;

    Node(){
        for(int i=0; i<26; i++) mark[i] = NULL;
        ew = 0;
        cp = 0;
    }

    bool containsKey(char ch){
        return (mark[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node){
        mark[ch - 'a'] = node;
    }

    Node* getNext(char ch){
        return mark[ch-'a'];
    }



};

class Trie {
private:
    Node* root;

public:
    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;

        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])) node->put(word[i], new Node());

            node = node->getNext(word[i]);
            node->cp++;
        }

        node->ew += 1;
    }

    int countWordsEqualTo(string word){
        Node* node = root;

        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])) return 0;
            
            node = node->getNext(word[i]);
        }

        return node->ew;
    }

    int countWordsStartsWith(string prefix){
        Node* node = root;

        for(int i=0; i<prefix.size(); i++){
            if(!node->containsKey(prefix[i])) return 0;

            node = node->getNext(prefix[i]);

        }

        return node->cp;
    }

    void erase(string word){
        Node* node = root;

        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                cout << "word doesnt exist" << '\n';
                return;
            }

            node = node->getNext(word[i]);
            node->cp--;
        }

        node->ew--;
    }
};


void solve() {
    Trie t = Trie();

    t.insert("apple");
    t.insert("apple");
    t.insert("apps");
    t.insert("apps");
    t.erase("apple");

    cout << t.countWordsStartsWith("app") << '\n';
    cout << t.countWordsStartsWith("abc") << '\n';
    cout << t.countWordsEqualTo("abc") << '\n';
    cout << t.countWordsEqualTo("apps") << '\n';
    cout << t.countWordsEqualTo("apple") << '\n';
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