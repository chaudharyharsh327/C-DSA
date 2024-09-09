#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char d){  //constructor
        this->data = d;
        //starting mein null pe point krega
        for(int i=0; i<26; i++){
             children[i] = NULL;
        }
       
        //initially false
        this->isTerminal = false;
    }
};

void insertWord(TrieNode* root, string word){
    cout<<"Inserting "<<word<<endl;
    //base case ab aage daalne ke liye koi word nhi bacha
    //toh us last word ko terminal mark krdo
    if(word.length() == 0){
        root->isTerminal= true;
        return;
    }

    char ch = word[0];
    //char ko index mein convert kia
    int index = ch - 'a';
    TrieNode* child;
    //present hai toh child se attach kro
    if(root->children[index] != NULL){
        child = root->children[index];
    }
    else{
        //not present hai toh child ko create kro aur root se attach kro
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    //recusrion sambhal lega
    //substr[1] mtlb one word jaaega at a time
    insertWord(child,word.substr(1));
    
}

bool searchWord(TrieNode* root, string word){
    if(word.length() == 0){
        return root->isTerminal;
    }
    char ch = word[0];
    //char ko index mein convert kia
    int index = ch - 'a';
    TrieNode* child;

    //present
    if(root->children[index] != NULL){
        child = root->children[index];
    }
    else{
        return false;
    }
    //reverse call
   return searchWord(child, word.substr(1));
}

int main(){
    //root node mein "-" rkha hai 
    TrieNode* root = new TrieNode('-');

    //root->insertWord("coding");
    insertWord(root, "coding");
    insertWord(root, "code");
    insertWord(root, "coder");
    insertWord(root, "codehelp");
    insertWord(root, "baba");
    insertWord(root, "baby");

    if(searchWord(root, "baby")){
        cout<<"present"<<endl;
    }
    else{
        cout<<"absent"<<endl;
    }
    return 0;
}