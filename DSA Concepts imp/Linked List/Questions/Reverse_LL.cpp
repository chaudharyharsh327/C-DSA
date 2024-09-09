#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

int getLength(Node *head) {
    int length = 0;
    Node *temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

void insertAtHead(Node *&head, Node *&tail, int data) {
    Node *newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data) {
    Node *newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
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

Node* reverseLinkedList(Node *head)
{
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    //eg== 1->2->3->4->NULL
    //head=1, prev=NULL, curr=1, forward=NULL

    //now at first interation
    //  forward = curr ->next;    forward =2
    //curr-> next = prev;   1->next points to NULL
    //  prev = curr; prev points to 1
    // curr = forward; curr ,oves to 2
    //LL  becomes 1->NULL
    //then
    //LL  becomes 2->1->NULL
    while(curr != NULL){
        forward = curr ->next;
        curr-> next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

void print(Node *head)
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

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtAnyPosition(head ,tail,1,1);
    insertAtAnyPosition(head ,tail,2,2);
    insertAtAnyPosition(head ,tail,3,3);
    insertAtAnyPosition(head ,tail,4,4);
    print(head);

   head =  reverseLinkedList(head);
    print(head);

}