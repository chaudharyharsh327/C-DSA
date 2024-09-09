// #include<iostream>
// using namespace std;

// class TrieNode{
//     public:
//     char value;
//     Trienode* children[26];
//     //taaki pta chle string kaha pr end ho rhi h
//     bool isterminal;

//     Trienode(char val){
//         this->value = val;
//         for(int i=0; i<26;i++){
//             children[i] = NULL;
//         }
//         this->isTerminal = false;
//     }

// }; 

// //insertion
// void insertNode(TrieNode* root, string word){ 
//     //base case
//     if(word.length() == 0){
//         root->isTerminal = true;
//         return;
        
//     }

//     char ch = word[0];
//     int index = ch -'a';
//     TireNode* child;

// }
// int main(){
//     TrieNode* root = new TrieNode('-');

// }


#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word){
        //recursion use krenge
        //base case
        if(word.length() == 0){
            //means poora word insert ho chuka hai
            root->isTerminal = true;
        }
        //assumption , word will be in CAPS
        int index = word[0] - 'A';
        TrieNode* child;

        //present hai word toh aage badgye
        if(root->children[index] != NULL){
            child = root -> children[index];

        }
        else{
            //absent hai toh insert kia aur aage bhad gye
            child = newTreeNode(word[0]);
            root->children[index]=child;

        }

        ///RECURSION
        insertUtil(child,word.substr[1]);



    }
    void insertWord(string word){
        insertUtil{root, word};
    }
};

int main(){
    Trie *t = new Trie();
    t->insertWord("Abcd");
    return 0; 
}