
////////////////////////////////////////////////////////////////////////////////////////////////////////
//BINARY TREE FROM INORDER AND PREORDER***********

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

int findPosition(int arr[], int n, int element){
    for(int i=0;i<n;i++){
        if(arr[i] == element){
            return i;
        }
    }
    return -1;
}

//build tree from inorder and preorder
Node*buildTreeFromPreOrderInOrder(int inorder[], int preorder[], int size, 
int & preIndex, int inorderStart, int inorderEnd){

    //base case
    if(preIndex >= size || inorderStart> inorderEnd){
        return NULL;
    }

    //Step A :preorder mein se root ka index nikalo
    int element = preorder[preIndex++];
    Node* root = new Node(element);
    //preorder ka root inorder mein search kr rhe h
    int pos = findPosition(inorder, size, element);

    //step B:root->left solve
    root->left = buildTreeFromPreOrderInOrder(inorder,preorder,size,preIndex,inorderStart, 
    pos-1);

    //Step C: root->right solve
     root->right = buildTreeFromPreOrderInOrder(inorder,preorder,size,preIndex,pos+1, 
    inorderEnd);

    return root;

    }
void levelOrderTraversal(Node *root){
    //root insert kro uske child insert krdo left to right
    queue<Node *> q;
    q.push(root);
    q.push(NULL); // null as a marker which shows level is complete
    while (q.size() > 1)
    {
        Node *front = q.front(); // front Node ko store krake pop krdo
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            q.push(NULL);
        }
        else
        {
            cout << front->data << " ";
            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
}



int main(){
    int inorder[] = {40,20,50,10,60,30,70};
    int preorder[] = {10,20,40,50,30,60,70};
    int size = 7;
    int preIndex=0;
    int inorderStart=0;
    int inorderEnd=size-1;

    cout<<"building tree: "<<endl;
    Node* root = buildTreeFromPreOrderInOrder(inorder,preorder,size,preIndex,inorderStart,inorderEnd);

    cout<<"Printing level order traversal"<<endl;
    levelOrderTraversal(root);
    return 0;
}
