// ///TREE SIZE    

// #include<iostream>
// using namespace std;
// class node{
//     public:
//     int val;
//     node* left;
//     node* right;
//     node(int val)
//     {
//         this->val = val;
//         left = NULL;
//         right = NULL;
//     }
// };
// node* create()
// {
//     int x;
//     cin>>x;
//     if(x==-1)
//     {
//         return NULL;
//     }
//     node* root = new node(x);
//     root->left = create();
//     root->right = create();
//     return root;
    
// }
// int total(node* root,int &count)
// {
//     if(root==NULL)
//     {
//         return 0;
//     }
//     count++;
//     total(root->left,count);
//     total(root->right,count);
//     return count;
// }
// int main()
// {
//     node* root = create();
//     int count = 0;
//     cout<<"total no. of nodes: "<<total(root,count);
//     return 0;
// }



