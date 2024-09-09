#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0; // curret object
    }
    // object create krne par use initialize krne ke liye constructor
    // banana padta hai
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    //kuch insert krna ho toh constructor call hoga like above
    //kuch delete krna ho toh destructor call hoga like below
    ~Node(){
        cout<<"destructor called for"<<this->data<<endl;
    }
    
};

void printLL(Node *head)
{
    // jab bhi LL ko head mein paas krenge toh uske liye hmesha new pointer banaenge
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int getLength(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// pass by refernce "&"
void insertAtHead(Node *&head, Node *&tail, int data)
{
    // empty LL
    if (head == NULL)
    {
        // create node
        Node *newNode = new Node(data);
        // update head
        head = newNode;
        tail = newNode;
    }
    else
    {
        // create a new node
        Node *newNode = new Node(data);
        // attach new node to head
        newNode->next = head;
        // update head
        head = newNode;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        // emptyLL
        // step1:create kro node
        Node *newNode = new Node(data);
        // step2:single node hai h entire list mein toh head
        // and tail ko ispe point krado
        head = newNode;
        tail = newNode;
    }
    else
    {
        // non empty LL
        //  create a new node
        Node *newNode = new Node(data);
        // tail node ko attach kro newNode se
        tail->next = newNode;
        // update tail
        tail = newNode;
    }
}

void insertAtAnyPosition(Node *&head, Node *&tail, int data, int position)
{
    int length = getLength(head);

    if (position <= 1)
    {
        insertAtHead(head, tail, data);
    }    
    else if (position > length)
    {
        insertAtTail(head, tail, data);
    }
    else
    {
        // insert at middle of LL

        // step1: create a new node
        Node *newNode = new Node(data);
        // step2: traverse prev // curr to position
        Node *prev = NULL;
        Node *curr = head;
        //intially prev null pr hai current head pr hai
        //while loop leke prev aur curr dono ko aage bhadenge
        while (position != 1)
        {
            prev = curr;
            curr = curr->next;
            position--;
        }
        // step3: attach prev to new Node
        prev->next = newNode;
        // step4: attack newNode to curr
        newNode->next = curr;
    }
}

void deleteNode(Node *&head, Node *&tail, int position){
    if(head==NULL){
        cout<<"Cannot delete, coz LL is empty"<<endl;
        return;
    }
    int len = getLength(head);
    if(position == 1){
        //first node ko delete kro or deleteAtHead

        Node*temp = head;
        head = head->next;
        temp->next=NULL;
        delete temp;
    }
    if(position == len){
        //last node delte krni hai
        Node*prev = head;
        while(prev-> next != tail){
            prev = prev->next;
        }
        //prev node ka link null kro
        prev->next =NULL;

        delete tail;

        tail = prev;


    }
    else{
        //middle node delte krni hai
        //step 1 set prev/curr pointers
        Node* prev = NULL;
        Node* curr = head;
        while(position != 1){
            position--;
            prev=curr;
            curr=curr->next;
        }

        //step 2: prev-> next mein curr ka next node add kro 
        prev->next = curr->next;

        //step3:node isolate kro
        curr->next = NULL;
        //step4: delete node
        delete curr;
    }
}

 
int main()
{

    // // creation of Node
    // Node *first = new Node(10);
    // Node *second = new Node(20);
    // Node *third = new Node(30);
    // Node *fourth = new Node(40);
    // Node *tail = fourth;

    // first->next = second;
    // second->next =third ;
    // third->next = fourth;

    // Node *head = first;
    // cout << "printing LL" << endl;
    // printLL(head);

    // cout << "Lenght of LL is:" << getLength(head) << endl;
    // insertAtTail(head, tail, 500);
    // printLL(head);

    // NOW CREATING LL WITH FUNCTIONS WE HAVE MADE
    Node *head = NULL;
    Node *tail = NULL;

    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtAnyPosition(head , tail, 1 ,0);
    printLL(head);
    cout<<endl;
    deleteNode(head,tail,3);
    printLL(head);
    cout<<endl;

    return 0;
}