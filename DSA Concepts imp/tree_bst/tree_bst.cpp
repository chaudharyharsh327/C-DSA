#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (root->data > data)
    {
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL); // null as a marker which shows level is complete
    while (q.size() > 1)
    {
        Node *front = q.front(); // front Node can be root or can be null
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

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root)
{ // inorder of bst is always sorted
    // base condtn
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void postOrder(Node *root)
{
    // base condtn
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// SEARCHING THE TARGET IN BST
Node *findNodeInBST(Node *root, int target)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == target)
        return root;

    if (target > root->data)
    {
        // right subtree mein search kro
        return findNodeInBST(root->right, target);
    }
    else
    {
        return findNodeInBST(root->left, target);
    }
}

// left jaaate rho sabse last left value minm hogi
int minVal(Node *root)
{
    Node *temp = root;
    if (temp == NULL)
    {
        return -1;
    }
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

// right jaaate rho sabse last right value maxm hogi
int maxVal(Node *root)
{
    Node *temp = root;
    if (temp == NULL)
    {
        return -1;
    }
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

Node *deleteNodeInBST(Node *root, int target)
{
    // base case
    if (root == NULL)
        return root;

    // Step 1
    Node *temp = findNodeInBST(root, target);
    // I want to delete temp
    if (temp->left == NULL && temp->right == NULL)
    {
        delete temp;
        return NULL;
    }

    else if (temp->left == NULL && temp->right != NULL)
    {
        Node *child = temp->right;
        delete temp;
        return child;
    }
    else if (temp->left != NULL && temp->right == NULL)
    {
        Node *child = temp->left;
        delete temp;
        return child;
    }
    else
    {
        // dono child exist krte hai
        // inorder predecessor of left subtree -> left subtree mein max value
        int inorderPre = maxVal(temp->left);
        temp->data = inorderPre;
        temp->left = deleteNodeInBST(temp->left, inorderPre); // Assign the return value to temp->left
        return temp;
    }
}

int main()
{
    Node *root = NULL;
    cout << "Enter the data for Node: " << endl;
    takeInput(root);
    cout << "Printing the tree" << endl;
    levelOrderTraversal(root);
    cout << endl;
    // cout<<"printing inorder: "<<endl;
    // inOrder(root);
    // cout<<endl;
    // cout<<"printing preorder: "<<endl;
    // preOrder(root);
    // cout<<endl;
    // cout<<"printing postorder: "<<endl;
    // postOrder(root);
    // cout<<endl;

    // bool ans = findNodeInBST(root, 155);
    // cout<<"Present or not: "<<ans<<endl;
    // cout<<endl<<"Minimum Value: "<<minVal(root)<<endl;
    // cout<<endl<<"Maximum Value: "<<maxVal(root)<<endl;
    cout << "Imran" << endl;
    deleteNodeInBST(root, 150);
    cout << "tree after deletion" << endl;
    levelOrderTraversal(root);

    return 0;
}