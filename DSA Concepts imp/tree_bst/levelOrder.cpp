#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

};

void levelOrderTraversal(Node* root){
      //root insert kro uske child insert krdo left to right
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        //A
        //har node ko front se nikalke print krna hai
        //temp is our final answer queue 
        Node* temp = q.front();//front node ko temp mein store krke pop krdo
        //B
        q.pop();
        //C
        cout<<temp->data<<" ";
        //D
        //agr temp ka koi left child exist krta hau toh queue mein insert krdo
        if(temp->left){
            q.push(temp->left);
        }
            //agr temp ka koi right child exist krta hau toh queue mein insert krdo
        if(temp->right){
            q.push(temp->right); 
        }

    }

}